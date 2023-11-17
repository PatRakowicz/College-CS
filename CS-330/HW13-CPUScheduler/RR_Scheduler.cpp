#include "hw13.h"

RR_Scheduler::RR_Scheduler(int sim_time, int quantum) : Scheduler(sim_time) {
	this->quantum = quantum;
}

void RR_Scheduler::run() {
	list < Process * > readyQueue;
	Process *currentProcess = nullptr;
	int timeSlice = 0;

	while (t < sim_time) {
		// Check for arriving processes
		for (auto &proc_pair: processes) {
			Process *proc = proc_pair.second;
			if (proc->arrival_t <= t && proc->status == INACTIVE) {
				proc->status = READY;
				proc->wait_t = t - proc->arrival_t;
				readyQueue.push_back(proc);
				cout << "Time " << t << ": Process " << proc->pid << " is ready (CPU cycles left: " << proc->cycles
					 << ")" << endl;
			}
		}

		// Scheduling
		if ((currentProcess == nullptr || timeSlice == 0) && !readyQueue.empty()) {
			if (currentProcess != nullptr && currentProcess->cycles > 0) {
				// Process is suspended
				cout << "Time " << t << ": Process " << currentProcess->pid << " is suspended (CPU cycles left: "
					 << currentProcess->cycles << ")" << endl;
				readyQueue.push_back(currentProcess);
			}
			currentProcess = readyQueue.front();
			readyQueue.pop_front();
			timeSlice = quantum;
			currentProcess->status = RUNNING;
			cout << "Time " << t << ": Process " << currentProcess->pid << " starts running (CPU cycles left: "
				 << currentProcess->cycles << ")" << endl;
		}

		// Execution
		if (currentProcess != nullptr) {
			int runTime = min(timeSlice, currentProcess->cycles);
			t += runTime;
			currentProcess->cycles -= runTime;
			timeSlice -= runTime;

			// Completion
			if (currentProcess->cycles == 0) {
				currentProcess->status = TERMINATED;
				done.push_back(currentProcess);
				cout << "Time " << t << ": Process " << currentProcess->pid << " terminates" << endl;
				currentProcess = nullptr;
			}
		} else {
			t++;  // Increment time if no process is ready
		}
	}
}
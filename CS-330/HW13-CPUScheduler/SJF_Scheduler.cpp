#include "hw13.h"

SJF_Scheduler::SJF_Scheduler(int sim_time) : Scheduler(sim_time) {}

void SJF_Scheduler::run() {
	list < Process * > ready;
	Process *currentProcess = nullptr;
	int minCycles;

	while (t < sim_time) {
		// Check for arriving processes
		for (auto &proc_pair: processes) {
			Process *proc = proc_pair.second;
			if (proc->arrival_t <= t && proc->status == INACTIVE) {
				proc->status = READY;
				proc->wait_t = t - proc->arrival_t;
				ready.push_back(proc);
				cout << "Time " << t << ": Process " << proc->pid << " is ready (CPU cycles left: " << proc->cycles
					 << ")" << endl;
			}
		}

		// Select process with the shortest job
		if (!ready.empty()) {
			auto shortestJob = ready.begin();
			minCycles = (*shortestJob)->cycles;
			for (auto it = ready.begin(); it != ready.end(); ++it) {
				if ((*it)->cycles < minCycles) {
					shortestJob = it;
					minCycles = (*it)->cycles;
				}
			}
			currentProcess = *shortestJob;
			ready.erase(shortestJob);

			// Execute the shortest job
			currentProcess->status = RUNNING;
			cout << "Time " << t << ": Process " << currentProcess->pid << " starts running (CPU cycles left: "
				 << currentProcess->cycles << ")" << endl;
			t += currentProcess->cycles; // Simulate process running to completion
			currentProcess->cycles = 0;
			currentProcess->status = TERMINATED;
			done.push_back(currentProcess); // Add to done list
			cout << "Time " << t << ": Process " << currentProcess->pid << " terminates" << endl;

			// Update wait times for other processes
			for (auto &proc: ready) {
				proc->wait_t += minCycles;
			}
		} else {
			t++;  // Increment time if no process is ready
		}
	}
}
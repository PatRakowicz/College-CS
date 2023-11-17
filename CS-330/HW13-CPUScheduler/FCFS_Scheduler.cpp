#include "hw13.h"

FCFS_Scheduler::FCFS_Scheduler(int sim_time) : Scheduler(sim_time){}

void FCFS_Scheduler::run(){
  multimap <int, Process *>::iterator it;
  list <Process *> ready;
  list <Process *>::iterator lit;
  Process *p, *p2;

  while(t < sim_time){
    for(it = processes.begin(); it != processes.end(); it++){
      p = it->second;
      if(p->arrival_t <= t && p->status == INACTIVE ){
        p->status = READY;
        p->wait_t = t - p->arrival_t;
        ready.push_back(p);
      }
    }

    if(!ready.empty()){
      //run first process of ready queue 
      p = ready.front();
      ready.pop_front();
      printf("%10d: scheduling PID %5d, CPU = %8d\n", t, p->pid, p->cycles);

      //run to completion
      t += p->cycles;
      p->status = TERMINATED;
      printf("%10d:            PID %8d  terminated\n", t, p->pid);


      //add process to done queue.. 
      done.push_back(p);

      //update wait times of all waiting processes
      for(lit = ready.begin(); lit != ready.end(); lit++){
        p2 = *lit;
        p2->status = WAITING;
        p2->wait_t += p->cycles;
      }
    } else {
      t++;
    }
  }
}

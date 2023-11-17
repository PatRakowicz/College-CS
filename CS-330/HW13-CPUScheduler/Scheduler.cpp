#include "hw13.h"

//DO NOT MODIFY

Scheduler::Scheduler(int sim_time){
  this->sim_time = sim_time;
}

void Scheduler::read_file(char *filename){
  ifstream ifs;
  ifs.open(filename);

  if(!ifs.is_open()){
    print_error_exit("bad file\n");
  }

  int id, arr, cyc; 

  while(ifs >> id >> arr >> cyc){
    Process *p = (Process *) malloc(sizeof(Process));
    p->pid = id;
    p->arrival_t = arr;
    p->cycles = cyc;
    p->status = INACTIVE;
    p->wait_t = 0;
    processes.insert(make_pair(arr, p));
  }
  ifs.close();
}

void Scheduler::print_stats(){
  double wait_t = 0;

  for(list<Process*>::iterator it = done.begin(); it != done.end(); it++){
    Process *p = *it;
    wait_t += p->wait_t;  
  }

  int throughput = done.size();
  wait_t /= (double) throughput; 

  int remaining = 0;
  for(multimap<int, Process *>::iterator it = processes.begin(); it != processes.end(); it++){
    if(it->second->status != TERMINATED){
      remaining++;
    }
  }

  fprintf(stderr,"=====================================================\n");
  fprintf(stderr,"Throughput        = %7d\n", throughput);
  fprintf(stderr,"Remaining         = %7d\n", remaining);
  fprintf(stderr,"Average wait time = %7.2lf\n", wait_t);
}


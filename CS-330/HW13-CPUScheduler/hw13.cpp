#include "hw13.h"
//DO NOT MODIFY

int main(int argc, char **argv)
{
  check_argc(argc);
  int sim_time = get_sim_time(argv);
  char *filename = get_filename(argv);
  int algo = get_algo(argv);
  int quantum;

  Scheduler *scheduler;
  switch(algo){
    case FCFS:
      scheduler = new FCFS_Scheduler(sim_time);
      break;

    case RR:
      quantum = get_quantum(argc, argv);
      scheduler = new RR_Scheduler(sim_time, quantum);
      break;

    case SJF:
      scheduler = new SJF_Scheduler(sim_time);
      break;
  }
  scheduler->read_file(filename);
  scheduler->run();
  scheduler->print_stats();
}

//helper functions 
void print_error_exit(const char *str)
{
  fprintf(stderr, "%s\n", str);
  exit(1);
}

void check_argc(int argc){
  if(argc != 4 && argc != 5) {
    print_error_exit("usage: ./hw13 sim_time file algorithm [quantum]");
  }
}

int get_sim_time(char **argv){
  int sim_time = atoi(argv[1]);
  if(sim_time <= 0) {
    print_error_exit("sim_time must be > 0");
  }
  return sim_time;
}

int get_algo(char **argv){
  char *algo = argv[3];
  if(strcmp(algo,"FCFS") == 0){
    return FCFS;
  } else if(strcmp(algo,"SJF") == 0){
    return SJF;
  }
  else if(strcmp(algo,"RR") == 0) {
    return RR;
  } else {
    print_error_exit("algorithm must be either \"FCFS\", \"SJF\", or \"RR\"");
  }
}

char* get_filename(char **argv){
  return argv[2];
}

int get_quantum(int argc, char **argv){
  if(argc != 5) {
    print_error_exit("algorithm RR must include quantum");
  }
  int quantum = atoi(argv[4]);
  if(quantum <= 0) {
    print_error_exit("quantum must be > 0");
  }
  return quantum;
}

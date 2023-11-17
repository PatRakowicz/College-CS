#pragma once

//DO NOT MODIFY
#include <iostream>
#include <fstream>
#include <list>
#include <map>
#include <cstdlib>
#include <cstdio>
#include <cstring>

#define FCFS 0
#define SJF 1
#define RR 2

#define INACTIVE 0
#define READY 1
#define RUNNING 2
#define WAITING 3
#define TERMINATED 4

using namespace std;

typedef struct {
  int pid;
  int status;
  int arrival_t;
  int cycles;
  int wait_t;
} Process;

class Scheduler {
  protected: 
    int t; 
    int sim_time;
    list <Process *> done;

  public: 
    Scheduler(int sim_time);
    multimap <int, Process *> processes;
    void read_file(char *filename);
    void print_stats();
    virtual void run() = 0;
};

class FCFS_Scheduler : public Scheduler {
  public: 
    FCFS_Scheduler(int sim_time);
    void run();
};

class SJF_Scheduler : public Scheduler {
  public: 
    SJF_Scheduler(int sim_time);
    void run();
};

class RR_Scheduler : public Scheduler {
  private:
    int quantum;
  public: 
    RR_Scheduler(int sim_time, int quantum);
    void run();
};

//helper functions
void print_error_exit(const char *str);
void check_argc(int argc);
int get_sim_time(char **argv);
int get_algo(char **argv);
char* get_filename(char **argv);
int get_quantum(int argc, char **argv);


#pragma once
#include <iostream>
#include <cstring>
using namespace std;

#define TABLE_SIZE 16
#define PAGE_SIZE 32
#define MAIN_MEMORY_SIZE TABLE_SIZE*PAGE_SIZE
#define DISK_SIZE 65536 
#define VERBOSE 0
#define byte unsigned char
#define HALF DISK_SIZE/2

void write_message(char *);
void add_vectors();
void random_memory();
int random(int, int);

class Disk {
    public:
        Disk();
        void write_page( int page_number, byte *buffer );
        void read_page( int page_number, byte *buffer );
    
    private:
        byte disk[DISK_SIZE];
};

class VirtualMemory {
  public:
    VirtualMemory();
    byte& operator[](const int);
    void print_table();
    float getFaultRate();
    void clearFaultRate();
    
  private:
    Disk disk;
    int page_table[TABLE_SIZE];
    byte main_memory[MAIN_MEMORY_SIZE];
    unsigned int next;
    unsigned long faults;
    unsigned long refs;
};

#pragma once
#include "Disk.h"
#include <unistd.h>
#include <sys/time.h>
#include <cstdint>

#define LEN_FILENAME 20
#define NUM_BLOCKS 8
#define DIR_SIZE BLOCK_SIZE/sizeof(unsigned int)

//unsigned int 4 bytes 
//64 - (20 + 4 + 4 + 4) => 32 / 4 = 8
typedef struct {
  char filename[LEN_FILENAME]; 
  unsigned int offset; //ofset into file
  unsigned int fcb_dir_index; //backref to location of FCB
  unsigned int size; //file's size
  unsigned int ptrs[NUM_BLOCKS]; //singly-indexed allocation 
} FCB;

class FileSystem {
  public:
    FileSystem();

    void reformat(); //reset free_list, FCB_dir
    FCB* fs_open(char *filename); //open file in read/write mode
    void fs_close(FCB *fcb); 
    int  fs_read(FCB *fcb, uint8_t* buffer, unsigned int num); 
    bool fs_write(FCB *fcb, uint8_t* buffer, unsigned int num); //append to file
    void fs_delete(char *filename);
    int fs_seek(FCB *fcb, int offset);
    void ls();

  private:
    Disk disk;
    uint8_t free_list[BLOCK_SIZE];
    unsigned int fcb_dir[DIR_SIZE];

    unsigned int find_empty_block();
    void   allocate(unsigned int block);
    void deallocate(unsigned int block);
    unsigned int find(char *filename);
};


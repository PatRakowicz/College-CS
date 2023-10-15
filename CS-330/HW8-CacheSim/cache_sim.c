#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

#define MAX_WAYS 8              //Up to 8-way cache
#define MAX_BLOCKS_PER_WAY 1024 //Support up to 1024 blocks per way
#define LATENCY_PER_HIT 1       //1 cycle latency for hits
#define LATENCY_PER_MISS 80     //80 cycle latency to go to RAM
#define TRACELEN 100000         //Longest trace length 
#define MAXLINELENGTH 20        //Longest line length

//Set Associative Cache global Variables
bool valid[MAX_WAYS][MAX_BLOCKS_PER_WAY]; //Valid bit
int tags[MAX_WAYS][MAX_BLOCKS_PER_WAY]; //Tag of stored memory
int lru[MAX_WAYS][MAX_BLOCKS_PER_WAY]; //LRU indicator.  False/0 means LRU is Way-0, True/1 means LRU is Way-1

int blocks_per_way = 0; //ACTUAL number of blocks per way based on user input
int index_bits = 0; //ACTUAL number of index bits based on user input
int num_ways = 0; //ACTUAL number of ways in our cache


// Initialize the cache
void initCache(void) {
    for (int i = 0; i < num_ways; i++) {
        for (int j = 0; j < blocks_per_way; j++) {
            valid[i][j] = false;
            tags[i][j] = 0;
            lru[i][j] = 0;
        }
    }
}


//Access cache based on random address
//Return true for cache hit, false for cache miss
bool accessCache(int addr) {
    int index = addr & ((1 << index_bits) -1);
    int tag = addr >> index_bits;
    int leastRecentlyUsedWay = 0;
    int minLRU = lru[0][index];

    for (int i = 0; i < num_ways; i++) {
        if (valid[i][index] && tags[i][index] == tag) {
            lru[i][index] = ++minLRU;
            return true;
        }
        if (lru[i][index] < minLRU) {
            leastRecentlyUsedWay = i;
            minLRU = lru[i][index];
        }
    }

    valid[leastRecentlyUsedWay][index] = true;
    tags[leastRecentlyUsedWay][index] = tag;
    lru[leastRecentlyUsedWay][index] = ++minLRU;
    return false;
}


////////////////////////////////////////////////////////
// DO NOT MODIFY ANY CODE BELOW!!!!!!!!!
////////////////////////////////////////////////////////


// Load our memory access into an array
int loadMemoryTrace(int *mem, char *filename) {
    char line[MAXLINELENGTH];
    int mem_access;
    int mem_count = 0;

    FILE *filePtr = fopen(filename, "r");
    if (filePtr == NULL) {
        printf("error: can't open file %s", filename);
        exit(1);
    }

    while (fgets(line, MAXLINELENGTH, filePtr)) {
        printf("%s", line);
        char *token = strtok(line, "#");
        mem_access = (int) strtol(token, NULL, 16);
        mem[mem_count] = mem_access;
        mem_count++;
    }

    return (mem_count - 1);
}


// Print cache contents
void printCache(void) {
    int i, j;
    printf("********** CACHE TAG CONTENTS **********\n");

    for (j = 0; j < blocks_per_way; j++) {
        for (i = 0; i < num_ways; i++) {
            printf("%08x     ", tags[i][j]);
        }
        printf("\n");
    }
    printf("****************************************\n");
}


// Main
int main(int argc, char **argv) {
    int memory_access_trace[TRACELEN];
    int mem_trace_size = 0;
    int addr = 0;
    bool hit = false;
    int hit_count = 0;
    int access_count = 0;
    int i = 0;
    float accuracy = 0.0;
    int total_latency = 0;

    if (argc != 4) {
        printf("Usage: ./a.out [tracename] [index_bit_size (0 -10)] [num_ways] \n");
        exit(0);
    }

    mem_trace_size = loadMemoryTrace(memory_access_trace, argv[1]);

    index_bits = atoi(argv[2]);
    blocks_per_way = pow(2, index_bits);
    num_ways = atoi(argv[3]);

    printf("**** Index Bits: %d **** \n", index_bits);
    printf("**** Blocks Per Way: %d **** \n", blocks_per_way);
    printf("**** Memory Trace Size: %d **** \n", mem_trace_size);

    initCache();

    for (i = 0; i < mem_trace_size; i++) {
        addr = memory_access_trace[i];
        hit = accessCache(addr);

        if (hit) {
            hit_count++;
            printf("**** Addr: %08x hit in cache ****\n", addr);
        } else {
            printf("**** Addr: %08x missed in cache ****\n", addr);
        }

        access_count++;
        printCache();
    }
    accuracy = (float) hit_count * 100.0 / (float) access_count;
    total_latency = hit_count * LATENCY_PER_HIT + (access_count - hit_count) * LATENCY_PER_MISS;

    printf("**** Cache Accuracy Stats ****\n");
    printf("**** Accuracy:%.2f, Hits:%d, Accesses:%d ****\n", accuracy, hit_count, access_count);
    printf("**** Memory Cycle Latency: %d\n", total_latency);

    return 0;
}
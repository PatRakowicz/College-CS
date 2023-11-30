#include "hw14.h"

byte& VirtualMemory::operator[](const int addr) {
    refs++;  // Increment reference counter
    int pageNumber = addr / PAGE_SIZE;
    int offset = addr % PAGE_SIZE;

    // Search for the page in the page table
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (page_table[i] == pageNumber) {
            // Page found in the table
            cerr << "requesting virtual address: " << addr << "\npage = " << pageNumber << ", offset = " << offset << "\nPAGE FOUND!" << endl;
            return main_memory[i * PAGE_SIZE + offset];
        }
    }

    // Page fault handling
    cerr << "requesting virtual address: " << addr << "\npage = " << pageNumber << ", offset = " << offset << "\nPAGE FAULT!" << endl;
    faults++;

    // Find an empty spot or use FCFS for replacement
    int replaceIndex = next;
    bool found = false;
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (page_table[i] == -1) {
            replaceIndex = i;
            found = true;
            break;
        }
    }

    // If no empty spot is found, increment 'next' for FCFS
    if (!found) {
        next = (next + 1) % TABLE_SIZE;
        replaceIndex = next;
    }

    // Load page from disk
    disk.read_page(pageNumber, &main_memory[replaceIndex * PAGE_SIZE]);
    page_table[replaceIndex] = pageNumber;

    cerr << (found ? "empty slot in page table: " : "NO SPACE in page table, swapping page: ") << replaceIndex << endl;

    // Return reference to byte in main memory
    return main_memory[replaceIndex * PAGE_SIZE + offset];
}

//DO NOT MODIFY BELOW 
VirtualMemory::VirtualMemory()
{
  for (int i = 0; i < TABLE_SIZE; i++) {
    page_table[i] = -1;
  }

  next = 0;
  faults = 0;
  refs = 0;
}

float VirtualMemory::getFaultRate()
{
  return 100 * (faults / (double) refs); 
}

void VirtualMemory::clearFaultRate()
{
  faults = refs = 0;
}

void VirtualMemory::print_table()
{
  for (int i = 0 ; i < TABLE_SIZE; i++) {
    cout << "page_table[" << i << "] = " << page_table[i] << endl;
  }
}

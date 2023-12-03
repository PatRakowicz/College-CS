#include "hw14.h"

// Executed on MAC
byte& VirtualMemory::operator[](const int addr) {
    refs++;

    if (addr < 0 || addr >= 65536) {
        cerr << "Invalid virtual address requested: " << addr << endl;
        return main_memory[0];
    }

    int pageNumber = addr / 32;
    int pageOffset = addr % 32;

    cerr << "Virtual address requested: " << addr << endl;
    cerr << "   Page number: " << pageNumber << ", Page offset: " << pageOffset << endl;

    int frameNumber = -1;
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (page_table[i] == pageNumber) {
            frameNumber = i;

            cerr << "PAGE FOUND!" << endl;
            cerr << "   page table entry: " << i << endl;
            cerr << "   physical address: " << (frameNumber * 32 + pageOffset) << endl;
            break;
        }
    }

    if (frameNumber == -1) {
        faults++;

        cerr << "PAGE FAULT!" << endl;

        int replaceFrame = next;
        next = (next + 1) % TABLE_SIZE;

        cerr << "   empty slot in page table: " << replaceFrame << endl;

        if (page_table[replaceFrame] != -1) {
            disk.write_page(page_table[replaceFrame], &main_memory[replaceFrame * 32]);
        }

        disk.read_page(pageNumber, &main_memory[replaceFrame * 32]);
        page_table[replaceFrame] = pageNumber;
        frameNumber = replaceFrame;

        cerr << "reading disk memory page: " << pageNumber << endl;
    }

    int physicalAddr = frameNumber * 32 + pageOffset;
    cerr << "   physical address: " << physicalAddr << endl;
    cerr << "============================" << endl;
    return main_memory[physicalAddr];
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

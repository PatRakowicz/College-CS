#include "hw14.h"

byte& VirtualMemory::operator[](const int addr) {
    cerr << "requesting virtual address: " << addr << endl;
    // Track memory references
    refs++;

    // Check for valid 16-bit address
    if (addr < 0 || addr >= 65536) {
        cerr << "Invalid virtual address requested: " << addr << endl;
        return main_memory[0]; // Returning a default reference to handle invalid address
    }

    // Calculate page number and page offset
    int pageNumber = addr / 32; // 32-byte pages
    int pageOffset = addr % 32;

    // Logging the virtual address, page number, and page offset
    cerr << "Virtual address requested: " << addr << endl;
    cerr << "Page number: " << pageNumber << ", Page offset: " << pageOffset << endl;

    // Check if page is in main memory
    int frameNumber = -1;
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (page_table[i] == pageNumber) {
            frameNumber = i;

            cerr << "PAGE FOUND!" << endl;
            cerr << "page table entry: " << i << endl;
            cerr << "physical address: " << (frameNumber * 32 + pageOffset) << endl;
//            cerr << "PAGE FOUND: " << i << ", Physical address: " << (frameNumber * 32 + pageOffset) << endl;
            break;
        }
    }

    if (frameNumber == -1) { // Page fault handling
        // Track page faults
        faults++;

        cerr << "PAGE FAULT!" << endl;

        // Find the next frame to replace (FCFS)
        int replaceFrame = next;
        next = (next + 1) % TABLE_SIZE;

        cerr << "empty slot in page table: " << replaceFrame << endl;


        // If the frame to be replaced contains a page, write it back to disk
        if (page_table[replaceFrame] != -1) {
            disk.write_page(page_table[replaceFrame], &main_memory[replaceFrame * 32]);
        }

        // Read the required page from disk into the frame
        disk.read_page(pageNumber, &main_memory[replaceFrame * 32]);
        page_table[replaceFrame] = pageNumber;
        frameNumber = replaceFrame;

        cerr << "reading disk memory page: " << pageNumber << endl;
    }

    // Calculate the physical address and return the reference to the byte
    int physicalAddr = frameNumber * 32 + pageOffset;
    cerr << "physical address: " << physicalAddr << endl;
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

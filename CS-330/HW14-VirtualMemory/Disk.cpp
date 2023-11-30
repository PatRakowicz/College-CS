#include "hw14.h"
//DO NOT MODIFY

Disk::Disk()
{
  memset(disk, 0x00, DISK_SIZE);
}

void Disk::write_page( int page_number, byte *buffer )
{
  int address = page_number * PAGE_SIZE;
  memcpy(&(disk[address]), buffer, PAGE_SIZE);
}

void Disk::read_page ( int page_number, byte *buffer )
{
  int address = page_number * PAGE_SIZE;
  memcpy(buffer, &(disk[address]), PAGE_SIZE);
}


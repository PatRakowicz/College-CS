#include "hw14.h"

VirtualMemory vm;

int main(){
/*

  // example #1
    vm[0] = 0xAA;
    vm[31] = 0xBB;
    vm[32] = 0xCC;
    vm[63] = 0xDD;
    vm[65504] = 0xEE;
    vm[65535] = 0xFF;
    cout << vm.getFaultRate() << "%" << endl;
    printf("vm[0] = 0x%x\n", vm[0]);
*/


  char *msg = strdup("Hello from Virtual Memory!!!");
  write_message(msg);
  add_vectors();
  random_memory();
}

//DO NOT MODIFY CODE BELOW
void write_message(char *msg){
  vm.clearFaultRate();
  for(int i = 0; i < strlen(msg); i++){
    vm[i*PAGE_SIZE] = msg[i]; 
  }
  for(int i = 0; i < strlen(msg); i++){
    cout << (char) vm[i*PAGE_SIZE]; 
  }
  cout << endl;
  cout << "fault rate: " << vm.getFaultRate() << "%" << endl;
}

void add_vectors()
{
  vm.clearFaultRate();

  //setup vector "A"
  cout << "setting up A" << endl;
  for (int i = 0; i < HALF; i++) {
    vm[i] = i % 256;
  }

  //setup vector "B"
  cout << "setting up B" << endl;
  for (int i = HALF; i < HALF * 2; i++) {
    vm[i] = i % 256;
  }

  //compute A + B
  cout << "computing A = A + B" << endl;
  for (int i = 0; i < HALF; i++) {
    vm[i] = vm[i] + vm[HALF + i];
  }

  for (int i = 0; i < HALF; i += PAGE_SIZE) {
    cout << "vm[" << i << "] = " << (int) vm[i] << endl;
  }

  cout << "fault rate: " << vm.getFaultRate() << "%" << endl;
}

void random_memory()
{
  vm.clearFaultRate();
  cout << "setting up random access pattern..." << endl;

  for (int i = 0; i < HALF * 2; i++) {
    vm[random(0, HALF * 2)] = random(0, 256);
  }

  for (int i = 0; i < HALF; i += PAGE_SIZE) {
    cout << "vm[" << i << "] = " << (int) vm[i] << endl;
  }

  cout << "fault rate: " << vm.getFaultRate() << "%" << endl;
}

int random(int low, int high){
  return rand() % high + low; 
}

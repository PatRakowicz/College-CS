#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Machine Definitions
#define NUMMEMORY 65536 // maximum number of data words in memory
#define NUMREGS 8 // number of machine registers


////////////////////////////////////////
// Opcode definitions
////////////////////////////////////////

//No-operation
#define NOOP 0

//R Type Instructions
#define ALU 1

//I Type Instructions
#define ADDI 2
#define ANDI 3

//General control functions
#define HALT 4

////////////////////////////////////////
// Function definitions
////////////////////////////////////////
#define ADD 0
#define SUB 1
#define AND 2
#define OR  3
#define XOR 4


//R Type Instructions
// |6-bits|5-bits|5-bit|5-bits|5-bits|6-bits|
// |  op  |  rs  |  rt |  rd  |unused| func |


//I Type Instruction
// |6-bits|5-bits|5-bit|16-bits  |
// |  op  |  rs  |  rd |immediate|


// Printable map of instructions
const char* opcode_to_str_map[] = {
    "noop",
    "alu",
    "addi",
    "andi",
    "halt"
};

// Printable map of functions for R-Type
const char* funct_to_str_map[] = {
    "add",
    "sub",
    "and",
    "or",
    "xor"
};


///////////////////////////////////////////////////////////////
// System State
///////////////////////////////////////////////////////////////

// Overall system state 
typedef struct stateStruct {
	int pc;
  int instr;
	int instrMem[NUMMEMORY];
	//int dataMem[NUMMEMORY]; //TBD - will we use datamem
	int reg[NUMREGS];
  int readRegA;
  int readRegB;
  int immed;
  int aluResult;
	int cycles; // number of cycles run so far
} stateType;


///////////////////////////////////////////////////////////////
// Inline Instructions to extract the content of machine instructions
///////////////////////////////////////////////////////////////

// Instruction Opcode
static inline int opcode(int instruction) {
    return (instruction >> 26) & 0x3F;
}

// Dest Register
static inline int field0(int instruction) {
    return (instruction >> 21) & 0x1F;
}

// Src Reg 1
static inline int field1(int instruction) {
    return (instruction >> 16) & 0x1F;
}

// Src Reg 2
static inline int field2(int instruction) {
    return instruction & 0xFFFF;
}

// Inst Field
static inline int instant(int instruction) {
    return instruction & 0xFFFF;
}

// Instruction Function
static inline int funct(int instruction) {
    return instruction & 0x3F;
}

///////////////////////////////////////////////////////////////
// Declarations of helper functions
///////////////////////////////////////////////////////////////

void printState(stateType*);
void printInstruction(int);
void readMachineCode(stateType*, char*);


///////////////////////////////////////////////////////////////
// Main Function
///////////////////////////////////////////////////////////////
int main(int argc, char *argv[]) {

    static stateType state;

    if (argc != 2) {
        printf("error: usage: %s <machine-code file>\n", argv[0]);
        exit(1);
    }

    readMachineCode(&state, argv[1]);

    int xx = 0;

    printf("SYSTEM STARTING STATE --- LOAD INSTRUCTIONS INTO MEMORY\n");
    printState(&state);

    while (opcode(state.instr) != HALT) {

        // Fetch 
        state.instr = state.instrMem[state.pc];
        state.pc++;

        // Decode
        state.readRegA = state.reg[field0(state.instr)];
        state.readRegB = state.reg[field1(state.instr)];
        state.immed = instant(state.instr);

        // Execute
        switch (opcode(state.instr)) {
        case ADDI:
            state.aluResult = state.readRegA + state.immed;
            break;
        case ANDI:
            state.aluResult = state.readRegA & state.immed;
            break;
        case ALU:
            switch (funct(state.instr)) {
            case ADD:
                state.aluResult = state.readRegA + state.readRegB;
                break;
            case SUB:
                state.aluResult = state.readRegA - state.readRegB;  // Changed to regB
                break;
            case AND:
                state.aluResult = state.readRegA & state.readRegB;
                break;
            case OR:
                state.aluResult = state.readRegA | state.readRegB;
                break;
            case XOR:
                state.aluResult = state.readRegA ^ state.readRegB;
                break;
            default:
                printf("Unknown ALU function\n");
                exit(1);
            }
            break;
        case NOOP:
            // Do nothing
            break;
        default:
            printf("Unknown instruction opcode\n");
            exit(1);
        }

        // Writeback
        switch (opcode(state.instr)) {
        case ADDI:
        case ANDI:
            state.reg[field1(state.instr)] = state.aluResult;
            break;
        case ALU:
            switch (funct(state.instr)) {
            case ADD:
            case AND:
            case XOR:
            case OR:
                state.reg[field0(state.instr)] = state.aluResult;  // Use field0 as destination
                break;
            case SUB:
                state.reg[field0(state.instr)] = state.aluResult;  // Use field0 as destination for SUB
                break;
            default:
                printf("Unknown ALU function\n");
                exit(1);
            }
            break;
        case NOOP:
        case HALT:
            // Do nothing
            break;
        default:
            printf("Unknown instruction opcode\n");
            exit(1);
        }


        state.cycles++;
        printState(&state);
    }
    printf("machine halted\n");
    printf("total of %d cycles executed\n", state.cycles);
    printf("final state of machine:\n");
    printState(&state);
}



///////////////////////////////////////////////////////////////
// Helper Functions
///////////////////////////////////////////////////////////////
//
/*
* DO NOT MODIFY ANY OF THE CODE BELOW.
*/

void printInstruction(int instr) {
    char instr_opcode_str[10];
    char instr_funct_str[10];
    int instr_opcode = opcode(instr);
   
    strcpy(instr_opcode_str, opcode_to_str_map[instr_opcode]);
    
    if (instr_opcode == ALU){
      int instr_funct = funct(instr);
      strcpy(instr_funct_str, funct_to_str_map[instr_funct]);
    }

    switch (instr_opcode) {
        case ALU:
            printf("%s %d %d %d", instr_funct_str, field0(instr), field1(instr), field2(instr));
            break;
        case ADDI:
        case ANDI:
            printf("%s %d %d %d", instr_opcode_str, field0(instr), field1(instr), instant(instr));
            break;
        case NOOP:
        case HALT:
            printf("%s", instr_opcode_str);
            break;
        default:
            printf(".fill %d", instr);
            return;
    }
}

void printState(stateType *statePtr) {
    printf("STATE AT CYCLE: %d\n", statePtr->cycles);
    printf("\tpc = %d\n", statePtr->pc);
    printf("\t\tinstruction = %x ( ", statePtr->instr);
    printInstruction(statePtr->instr);
    printf(" )\n");

    printf("\tregisters:\n");
    for (int i=0; i<NUMREGS; ++i) {
        printf("\t\treg[ %d ] = %d\n", i, statePtr->reg[i]);
    }
    printf("\treadRegA = %d", statePtr->readRegA);
    printf("\n");
    printf("\treadRegB = %d", statePtr->readRegB);
    printf("\n"); 
    printf("\timmed = %d", statePtr->immed);
    printf("\n"); 
    printf("\taluResult = %d", statePtr->aluResult);
    printf("\n");

    printf("end state\n");
   
}


// Load our "program file" into our instruction memory
#define MAXLINELENGTH 100 // MAXLINELENGTH is the max number of characters we read

void readMachineCode(stateType *state, char* filename) {
    char line[MAXLINELENGTH];
    int instruction;
    int inst_count = 0;

    FILE *filePtr = fopen(filename, "r");
    if (filePtr == NULL) {
        printf("error: can't open file %s", filename);
        exit(1);
    }

    printf("loading instruction memory with program:\n");
    
    while(fgets(line, MAXLINELENGTH, filePtr)) {
        printf("%s", line);
        char* token = strtok(line, "#");
        instruction = (int)strtol(token, NULL, 16);
        //instruction = (int)strtol(line, NULL, 16);
        state->instrMem[inst_count] = instruction;
        inst_count++;
    }
}

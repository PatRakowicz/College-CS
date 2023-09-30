#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

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
//BEQ instruction uses I-type format
#define BEQ 6

//General control functions
#define HALT 4

//Jump instruction opcode
#define JUMP 5

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


//Jump Type Instruction
// |6-bits|10-bits|16-bits  |
// |  op  |unised |immediate|




// Printable map of instructions
const char *opcode_to_str_map[] = {
		"noop",
		"alu",
		"addi",
		"andi",
		"halt",
		"jump",
		"beq"
};

// Printable map of functions for R-Type
const char *funct_to_str_map[] = {
		"add",
		"sub",
		"and",
		"or",
		"xor"
};


///////////////////////////////////////////////////////////////
// Each of these structs tracks the STATE of a particular pipeline stage
///////////////////////////////////////////////////////////////

typedef struct IFIDStruct {
	int instr;
	int pcPlus1;
} IFIDType;

typedef struct IDEXStruct {
	int instr;
	int readRegA;
	int readRegB;
	int offset;
} IDEXType;

typedef struct EXMEMStruct {
	int instr;
	int branchTarget;
	int takeBranch;
	int aluResult;
} EXMEMType;

typedef struct MEMWBStruct {
	int instr;
	int writeData;
} MEMWBType;

typedef struct WBENDStruct {
	int instr;
	int writeData;
} WBENDType;

// Overall system state 
typedef struct stateStruct {
	int pc;
	int instrMem[NUMMEMORY];
	//int dataMem[NUMMEMORY]; //TBD - will we use datamem
	int reg[NUMREGS];
	IFIDType IFID;
	IDEXType IDEX;
	EXMEMType EXMEM;
	MEMWBType MEMWB;
	WBENDType WBEND;
	int cycles; // number of cycles run so far
} stateType;


///////////////////////////////////////////////////////////////
// Inline Instructions to extract the content of machine instructions
///////////////////////////////////////////////////////////////

// Instruction Opcode
static inline int opcode(int instruction) {
	return instruction >> 26;
}

// RS
static inline int field0(int instruction) {
	return (instruction >> 21) & 0x1F;
}

// RT
static inline int field1(int instruction) {
	return (instruction >> 16) & 0x1F;
}

// RD
static inline int field2(int instruction) {
	return (instruction >> 11) & 0x1F;
}

// Inst Field
static inline int instant(int instruction) {
	return (instruction) & 0xFFFF;
}

// Instruction Function
static inline int funct(int instruction) {
	return instruction & 0x3F;
}

///////////////////////////////////////////////////////////////
// Declarations of helper functions
///////////////////////////////////////////////////////////////

void printState(stateType *);

void printInstruction(int);

void readMachineCode(stateType *, char *);

int sign_extend(int immediate) { return (int) (short) immediate; }

int get_offset(int instr) { return instr & 0xFFFF; }

///////////////////////////////////////////////////////////////
// STUDENT CODE: students will write these funtions
///////////////////////////////////////////////////////////////


void if_stage(stateType *statePtr, stateType *newStatePtr) {
	newStatePtr->IFID.instr = statePtr->instrMem[statePtr->pc];
	newStatePtr->IFID.pcPlus1 = statePtr->pc + 1;
	newStatePtr->pc = statePtr->EXMEM.takeBranch ? statePtr->EXMEM.branchTarget : (statePtr->pc + 1);
}

void id_stage(stateType *statePtr, stateType *newStatePtr) {
	int instr = statePtr->IFID.instr;
	int opcode_val = opcode(instr);

	newStatePtr->IDEX.instr = instr;
	newStatePtr->IDEX.readRegA = statePtr->reg[field0(instr)];
	newStatePtr->IDEX.readRegB = statePtr->reg[field1(instr)];
	newStatePtr->IDEX.offset = instant(instr);

	if(opcode_val == BEQ) {
		newStatePtr->IDEX.offset = (int16_t)newStatePtr->IDEX.offset;
	}
}

void ex_stage(stateType *statePtr, stateType *newStatePtr) {
	int instr = statePtr->IDEX.instr;
	int opcode_val = opcode(instr);
	newStatePtr->EXMEM.instr = instr;
	newStatePtr->EXMEM.takeBranch = 0;

	if (opcode_val == ALU) {
		switch (funct(instr)) {
			case ADD:
				newStatePtr->EXMEM.aluResult = statePtr->IDEX.readRegA + statePtr->IDEX.readRegB;
				break;
			case SUB:
				newStatePtr->EXMEM.aluResult = statePtr->IDEX.readRegA - statePtr->IDEX.readRegB;
				break;
			case AND:
				newStatePtr->EXMEM.aluResult = statePtr->IDEX.readRegA & statePtr->IDEX.readRegB;
				break;
			case OR:
				newStatePtr->EXMEM.aluResult = statePtr->IDEX.readRegA | statePtr->IDEX.readRegB;
				break;
			case XOR:
				newStatePtr->EXMEM.aluResult = statePtr->IDEX.readRegA ^ statePtr->IDEX.readRegB;
				break;
			default:
				// if needed for error, left blank
				break;
		}
	} else if (opcode_val == ADDI) {
		newStatePtr->EXMEM.aluResult = statePtr->IDEX.readRegA + statePtr->IDEX.offset;
	} else if (opcode_val == ANDI) {
		newStatePtr->EXMEM.aluResult = statePtr->IDEX.readRegA & statePtr->IDEX.offset;
	} else if (opcode_val == BEQ) {
		newStatePtr->EXMEM.takeBranch = (statePtr->IDEX.readRegA == statePtr->IDEX.readRegB);
		newStatePtr->EXMEM.branchTarget = statePtr->IFID.pcPlus1 + (int16_t)statePtr->IDEX.offset;
	} else if (opcode_val == JUMP) {
		newStatePtr->EXMEM.takeBranch = 1;
		newStatePtr->EXMEM.branchTarget = statePtr->IFID.pcPlus1 + (int16_t)statePtr->IDEX.offset;
	} else {
		newStatePtr->EXMEM.aluResult = 0;
	}
}

void mem_stage(stateType *statePtr, stateType *newStatePtr) {
	int instr = statePtr->EXMEM.instr;

	newStatePtr->MEMWB.instr = instr;
	newStatePtr->MEMWB.writeData = statePtr->EXMEM.aluResult;
}

void wb_stage(stateType *statePtr, stateType *newStatePtr) {
	int instr = statePtr->MEMWB.instr;
	int opcode_val = opcode(instr);

	newStatePtr->WBEND.instr = instr;
	newStatePtr->WBEND.writeData = statePtr->MEMWB.writeData;

	if (opcode_val != BEQ && opcode_val != JUMP && opcode_val != NOOP) {
		int writeReg = field1(instr);
		if (opcode_val == ALU) {
			writeReg = field2(instr);
		}
		newStatePtr->reg[writeReg] = statePtr->MEMWB.writeData;
	}
}

///////////////////////////////////////////////////////////////
// Main Function
///////////////////////////////////////////////////////////////
int main(int argc, char *argv[]) {

	static stateType state, newState;

	if (argc != 2) {
		printf("error: usage: %s <machine-code file>\n", argv[0]);
		exit(1);
	}

	readMachineCode(&state, argv[1]);

	int xx = 0;

	printf("SYSTEM STARTING STATE --- LOAD INSTRUCTIONS INTO MEMORY\n");
	printState(&state);

	while (opcode(state.MEMWB.instr) != HALT) {
		newState = state;
		newState.cycles++;

		/* ---------------------- IF stage --------------------- */
		if_stage(&state, &newState);

		/* ---------------------- ID stage --------------------- */
		id_stage(&state, &newState);

		/* ---------------------- EX stage --------------------- */
		ex_stage(&state, &newState);

		/* --------------------- MEM stage --------------------- */
		mem_stage(&state, &newState);

		/* ---------------------- WB stage --------------------- */
		wb_stage(&state, &newState);

		/* ------------------------ END ------------------------ */
		state = newState; /* this is the last statement before end of the loop. It marks the end
        of the cycle and updates the current state with the values calculated in this cycle */
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

	if (instr_opcode == ALU) {
		int instr_funct = funct(instr);
		strcpy(instr_funct_str, funct_to_str_map[instr_funct]);
	}

	switch (instr_opcode) {
		case ALU:
			printf("%s %d %d %d", instr_funct_str, field0(instr), field1(instr), field2(instr));
			break;
		case ADDI:
		case ANDI:
		case BEQ:
			printf("%s %d %d %d", instr_opcode_str, field0(instr), field1(instr), (short) instant(instr));
			break;
		case NOOP:
		case HALT:
			printf("%s", instr_opcode_str);
			break;
		case JUMP:
			printf("%s %d", instr_opcode_str, (short) instant(instr));
			break;
		default:
			printf(".fill %d", instr);
			return;
	}
}

void printState(stateType *statePtr) {
	printf("STATE AT CYCLE: %d\n", statePtr->cycles);
	printf("\tpc = %d\n", statePtr->pc);

	printf("\tregisters:\n");
	for (int i = 0; i < NUMREGS; ++i) {
		printf("\t\treg[ %d ] = %d\n", i, statePtr->reg[i]);
	}

	// IF/ID
	printf("\tIF/ID pipeline register:\n");
	printf("\t\tinstruction = %x ( ", statePtr->IFID.instr);
	printInstruction(statePtr->IFID.instr);
	printf(" )\n");
	printf("\t\tpcPlus1 = %d", statePtr->IFID.pcPlus1);
	printf("\n");

	// ID/EX
	int idexOp = opcode(statePtr->IDEX.instr);
	printf("\tID/EX pipeline register:\n");
	printf("\t\tinstruction = %x ( ", statePtr->IDEX.instr);
	printInstruction(statePtr->IDEX.instr);
	printf(" )\n");
	printf("\t\treadRegA = %d", statePtr->IDEX.readRegA);
	printf("\n");
	printf("\t\treadRegB = %d", statePtr->IDEX.readRegB);
	printf("\n");

	// EX/MEM
	int exmemOp = opcode(statePtr->EXMEM.instr);
	printf("\tEX/MEM pipeline register:\n");
	printf("\t\tinstruction = %x ( ", statePtr->EXMEM.instr);
	printInstruction(statePtr->EXMEM.instr);
	printf(" )\n");
	printf("\t\taluResult = %d", statePtr->EXMEM.aluResult);
	printf("\n");

	// MEM/WB
	int memwbOp = opcode(statePtr->MEMWB.instr);
	printf("\tMEM/WB pipeline register:\n");
	printf("\t\tinstruction = %x ( ", statePtr->MEMWB.instr);
	printInstruction(statePtr->MEMWB.instr);
	printf(" )\n");
	printf("\t\twriteData = %d", statePtr->MEMWB.writeData);
	printf("\n");

	// WB/END
	int wbendOp = opcode(statePtr->WBEND.instr);
	printf("\tWB/END pipeline register:\n");
	printf("\t\tinstruction = %x ( ", statePtr->WBEND.instr);
	printInstruction(statePtr->WBEND.instr);
	printf(" )\n");
	printf("\t\twriteData = %d", statePtr->WBEND.writeData);
	printf("\n");
	printf("end state\n");

}


// Load our "program file" into our instruction memory
#define MAXLINELENGTH 100 // MAXLINELENGTH is the max number of characters we read

void readMachineCode(stateType *state, char *filename) {
	char line[MAXLINELENGTH];
	int instruction;
	int inst_count = 0;

	FILE *filePtr = fopen(filename, "r");
	if (filePtr == NULL) {
		printf("error: can't open file %s", filename);
		exit(1);
	}

	printf("loading instruction memory with program:\n");

	while (fgets(line, MAXLINELENGTH, filePtr)) {
		printf("%s", line);
		char *token = strtok(line, "#");
		instruction = (int) strtol(token, NULL, 16);
		//instruction = (int)strtol(line, NULL, 16);
		state->instrMem[inst_count] = instruction;
		inst_count++;
	}
}

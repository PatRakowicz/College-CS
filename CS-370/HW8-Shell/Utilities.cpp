//
// Created by Rako on 2/03/2024.
//
#include "Utilities.h"

void Utilities::freeArgs(std::vector<char *> &args) {
	for (char *arg: args) {
		delete[] arg; // Free each argument's memory
	}
}

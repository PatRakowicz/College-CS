//
// Created by Rako on 3/23/24.
//
// I am aware you cant keep giving me extra points for file organization
// still gonna do it, good code practice

#include "execCommand.h"
#include <cstring>
#include <unistd.h>
#include <stdlib.h>
#include <iostream>

void execCommand(const char *cmd);

std::vector<char *> parseCommand(char *cmd) {
    std::vector<char *> args;
    char *p = strtok(cmd, "_");
    while (p) {
        args.push_back(p);
        p = strtok(nullptr, "_");
    }
    args.push_back(nullptr); // null-terminate the list of arguments
    return args;
}

void execCommand(const char *cmd) {
    std::vector<char *> args = parseCommand(const_cast<char *>(cmd));
    execvp(args[0], args.data());
    perror("execvp failed");
    exit(EXIT_FAILURE);
}

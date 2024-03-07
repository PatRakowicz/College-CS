//
// Created by Rako on 3/6/24.
//

#ifndef SHELL2_IOHANDLER_H
#define SHELL2_IOHANDLER_H

#include <fstream>
#include <iostream>
#include <map>

class IOHandler {
public:
    IOHandler(const std::map<std::string, std::string>& args, bool appendMode);
    ~IOHandler();
    void processInput();

private:
    std::istream* in = nullptr;
    std::ostream* out = nullptr;
    std::ostream* err = nullptr;
    std::ifstream inFile;
    std::ofstream outFile;
    std::ofstream errFile;
};

#endif //SHELL2_IOHANDLER_H

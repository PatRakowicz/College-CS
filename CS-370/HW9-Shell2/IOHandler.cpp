//
// Created by Rako on 3/6/24.
//

#include "IOHandler.h"


IOHandler::IOHandler(const std::map <std::string, std::string> &args, bool appendMode) {
    // Input
    if (args.find("in") != args.end()) {
        inFile.open(args.at("in"));
        if (!inFile.is_open()) {
            std::cerr << "Failed to open input file: " << args.at("in") << std::endl;
            exit(1);
        }
        in = &inFile;
    } else {
        in = &std::cin;
    }

    //Output
    if (args.find("out") != args.end()) {
        outFile.open(args.at("out"), appendMode ? std::ios::app : std::ios::out);
        out = &outFile;
    } else {
        out = &std::cout;
    }
    if (args.find("err") != args.end()) {
        errFile.open(args.at("err"), appendMode ? std::ios::app : std::ios::out);
        err = &errFile;
    } else {
        err = &std::cerr;
    }
}

IOHandler::~IOHandler() {
    if (inFile.is_open()) inFile.close();
    if (outFile.is_open()) outFile.close();
    if (errFile.is_open()) errFile.close();
}

void IOHandler::processInput() {
    std::string line;
    while (std::getline(*in, line)) {
        *out << "stdout: " << line << std::endl;
        *err << "stderr: " << line << std::endl;
    }
}

//
// Created by Rako on 3/6/24.
//

#include "IOHandler.h"
#include <map>
#include <string>

int main(int argc, char* argv[]) {
    std::map<std::string, std::string> args;
    bool appendMode = false;

    for (int i = 1; i < argc; ++i) {
        std::string arg(argv[i]);
        if (arg == "-append") {
            appendMode = true;
        } else {
            size_t pos = arg.find('=');
            if (pos != std::string::npos) {
                args[arg.substr(0, pos)] = arg.substr(pos + 1);
            }
        }
    }

    IOHandler ioHandler(args, appendMode);
    ioHandler.processInput();

    return 0;
}
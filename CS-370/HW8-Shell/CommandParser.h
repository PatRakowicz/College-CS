//
// Created by Rako on 2/03/2024.
//

#ifndef HW8_SHELL_I_COMMANDPARSER_H
#define HW8_SHELL_I_COMMANDPARSER_H


#include <string>
#include <vector>

class CommandParser {
public:
	static std::vector<char*> parseInput(const std::string& input);
};


#endif //HW8_SHELL_I_COMMANDPARSER_H

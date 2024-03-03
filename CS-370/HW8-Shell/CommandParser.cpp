//
// Created by Rako on 2/03/2024.
//

#include "CommandParser.h"
#include <sstream>
#include <cstring>

std::vector<char *> CommandParser::parseInput(const std::string &input) {
	std::istringstream iss(input);
	std::string token;
	std::vector<char *> args;
	while (iss >> token) {
		char *arg = new char[token.size() + 1];
		std::copy(token.begin(), token.end(), arg);
		arg[token.size()] = '\0';
		args.push_back(arg);
	}
	args.push_back(nullptr); // Null-terminate the array of arguments
	return args;
}

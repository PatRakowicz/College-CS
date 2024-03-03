#include "CommandParser.h"
#include "Utilities.h"
#include <iostream>
#include <unistd.h>
#include <sys/wait.h>

int main() {
	std::string input;
	while (true) {
		std::cout << "MY_UNIX> ";
		std::getline(std::cin, input);

		if (input == "exit" || std::cin.eof()) break;
		if (input.empty()) continue;

		std::vector<char *> args = CommandParser::parseInput(input);

		pid_t pid = fork();
		if (pid == 0) {
			if (execvp(args[0], args.data()) == -1) {
				std::cerr << "Command execution failed\n";
			}
			exit(EXIT_FAILURE);
		} else if (pid > 0) {
			int status;
			waitpid(pid, &status, 0);
		} else {
			std::cerr << "Failed to create process\n";
		}

		Utilities::freeArgs(args);
	}

	return 0;
}
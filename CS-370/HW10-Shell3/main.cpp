//
// Created by Rako on 3/23/24.
//
#include "execCommand.h"
#include <sys/wait.h>
#include <unistd.h>
#include <iostream>

int main(int argc, char* argv[]) {
    if (argc < 3) {
        std::cerr << "Usage: " << argv[0] << " command1 command2 ..." << std::endl;
        return EXIT_FAILURE;
    }

    int fds[2]; // file descriptors for the pipe
    int in_fd = 0; // file descriptor for input to the next command

    for (int i = 1; i < argc; ++i) {
        pipe(fds);

        if (fork() == 0) { // Child process
            if (i > 1) { // Not the first command
                dup2(in_fd, 0); // Set stdin to the read end of the previous pipe
                close(in_fd);
            }
            if (i < argc - 1) { // Not the last command
                close(fds[0]); // Close the read end of the pipe
                dup2(fds[1], 1); // Set stdout to the write end of the current pipe
                close(fds[1]);
            }
            execCommand(argv[i]);
        } else { // Parent process
            if (i > 1) close(in_fd);
            close(fds[1]); // Close the write end of the pipe
            in_fd = fds[0]; // Save the read end of the current pipe for the next iteration
            if (i == argc - 1) close(fds[0]);
        }
    }

    while (wait(nullptr) > 0); // Wait for all child processes to finish

    return EXIT_SUCCESS;
}

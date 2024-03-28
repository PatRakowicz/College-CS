#include <iostream>
#include <vector>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <cstring>

using namespace std;

void childProcess(int maxSleepTime, const char *url);

void startSignalHandler(int signum);

void stopSignalHandler(int signum);

volatile sig_atomic_t startFlag = 0;
volatile sig_atomic_t stopFlag = 0;

int main(int argc, char *argv[]) {
    if (argc != 4) {
        cerr << "Usage: " << argv[0] << " <N processes> <maxSleepTime> <URL>" << endl;
        return 1;
    }

    int n = atoi(argv[1]);
    int maxSleepTime = atoi(argv[2]);
    const char *url = argv[3];

    cout << "enter \"start\" to begin" << endl;
    cout << url << endl;
    cout << "enter \"stop\" to end" << endl;

    vector <pid_t> children;

    for (int i = 0; i < n; ++i) {
        pid_t pid = fork();
        if (pid == 0) {
            childProcess(maxSleepTime, url);
            exit(0);
        } else if (pid > 0) {
            children.push_back(pid);
        } else {
            cerr << "Failed to fork" << endl;
            return 1;
        }
    }

    string userInput;
    while (true) {
        cin >> userInput;
        if (userInput == "start") {
            for (pid_t child: children) {
                kill(child, SIGUSR1);
            }
        } else if (userInput == "stop") {
            for (pid_t child: children) {
                kill(child, SIGUSR2);
            }
            break;
        }
    }

    for (pid_t child: children) {
        waitpid(child, NULL, 0);
    }

    return 0;
}

void childProcess(int maxSleepTime, const char *url) {
    signal(SIGUSR1, startSignalHandler);
    signal(SIGUSR2, stopSignalHandler);

    pause();

    while (!stopFlag) {
        if (startFlag) {
            int sleepTime = rand() % maxSleepTime;
            usleep(sleepTime * 1000);

            cerr << getpid() << ": sending request" << endl;
            string command = "wget -qO- " + string(url) + " > /dev/null";
            system(command.c_str());
        }
    }
}

void startSignalHandler(int signum) {
    startFlag = 1;
}

void stopSignalHandler(int signum) {
    exit(0);
}

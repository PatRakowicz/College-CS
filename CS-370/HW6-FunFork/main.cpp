#include <iostream>
#include <fstream>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <time.h>

using namespace std;

// generate a random arithmetic operation
char getRandomOp() {
    const char ops[] = {'+', '-', '*', '/', '%'};
    return ops[rand() % 5];
}

// compute arithmetic expressions
double computeExpression(int x, char op, int y) {
    switch (op) {
        case '+': return x + y;
        case '-': return x - y;
        case '*': return x * y;
        case '/': return y == 0 ? -1 : x / (double)y;
        case '%': return y == 0 ? -1 : x % y;
        default: return -1;
    }
}

int main(int argc, char **argv) {
    if (argc != 3) {
        cerr << "usage: " << argv[0] << " fileName N" << endl;
        return 1;
    }

    const char* fileName = argv[1];
    int N = atoi(argv[2]);

    srand(time(NULL));

    pid_t pid = fork();

    if (pid == 0) {
        // Child process
        ofstream outFile(fileName);
        for (int i = 0; i < N; ++i) {
            int x = rand() % 10;
            char op = getRandomOp();
            int y = rand() % 10;
            outFile << x << " " << op << " " << y << endl;
        }
        outFile.close();
    } else if (pid > 0) {
        // Parent process
        wait(NULL);

        ifstream inFile(fileName);
        int x, y;
        char op;
        while (inFile >> x >> op >> y) {
            double result = computeExpression(x, op, y);
            if (result == -1) {
                cout << x << " " << op << " " << y << " = " << "-1" << endl;
            } else {
                cout << x << " " << op << " " << y << " = " << result << endl;
            }
        }
        inFile.close();
    } else {
        cerr << "Fork failed" << endl;
        return 2;
    }

    return 0;
}

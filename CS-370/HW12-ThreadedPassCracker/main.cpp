#include "PasswordGenerator.h"
#include "PasswordCracker.h"
#include <iostream>
#include <cstdlib> // for std::stoi

int main(int argc, char** argv) {
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " <words.txt> <seed> <N>\n";
        return 1;
    }

    std::string fileName = argv[1];
    int seed = std::stoi(argv[2]);
    int N = std::stoi(argv[3]);

    PasswordGenerator generator(fileName);
    std::string password = generator.generatePassword(seed);
    std::cout << "Password is " << password << std::endl;

    PasswordCracker cracker(generator.getWords(), password, N);
    cracker.crackPassword();

    return 0;
}

//
// Created by Rako on 4/4/24.
//

#ifndef HW12_THREADEDPASSCRACKER_PASSWORDCRACKER_H
#define HW12_THREADEDPASSCRACKER_PASSWORDCRACKER_H

#include <vector>
#include <string>
#include <atomic>
#include <thread>

class PasswordCracker {
private:
    std::vector<std::string> words;
    std::string targetPassword;
    int numThreads;
    std::atomic<bool> found{false};

public:
    PasswordCracker(const std::vector<std::string>& words, const std::string& password, int N);
    void crackPassword();
    static void worker(int id, const std::vector<std::string>& words, const std::string& password, std::atomic<bool>& foundFlag, int numThreads);
};


#endif //HW12_THREADEDPASSCRACKER_PASSWORDCRACKER_H

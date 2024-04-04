//
// Created by Rako on 4/4/24.
//
#include "PasswordCracker.h"
#include <iostream>
#include <vector>
#include <atomic>
#include <thread>

PasswordCracker::PasswordCracker(const std::vector<std::string>& words, const std::string& password, int N)
        : words(words), targetPassword(password), numThreads(N) {}

void PasswordCracker::worker(int id, const std::vector<std::string>& words, const std::string& password, std::atomic<bool>& foundFlag, int numThreads) {
    long long totalCombinations = static_cast<long long>(words.size()) * (words.size() - 1);
    long long perThread = totalCombinations / numThreads;
    long long startIdx = perThread * id;
    long long endIdx = (id + 1 == numThreads) ? totalCombinations : startIdx + perThread;

    for (long long i = startIdx; i < endIdx && !foundFlag.load(); ++i) {
        long long firstIdx = i / (words.size() - 1);
        long long secondIdx = i % (words.size() - 1);
        if (secondIdx >= firstIdx) ++secondIdx;

        std::string attempt = words[firstIdx] + words[secondIdx];
        if (attempt == password) {
            std::cout << id << ": found password " << attempt << std::endl;
            foundFlag.store(true);
            break;
        }
    }
}

void PasswordCracker::crackPassword() {
    std::vector<std::thread> threads;

    for (int i = 0; i < numThreads; ++i) {
        threads.emplace_back(std::thread(&PasswordCracker::worker, i, std::cref(words), std::cref(targetPassword), std::ref(found), numThreads));
    }

    for (auto& thread : threads) {
        if (thread.joinable()) {
            thread.join();
        }
    }
}

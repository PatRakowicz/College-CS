//
// Created by Rako on 4/4/24.
//

#include "PasswordGenerator.h"
#include <fstream>
#include <random>

PasswordGenerator::PasswordGenerator(const std::string& fileName) {
    std::ifstream file(fileName);
    std::string word;
    while (file >> word) {
        words.push_back(word);
    }
}

std::string PasswordGenerator::generatePassword(int seed) {
    std::mt19937 rng(seed);
    std::uniform_int_distribution<int> dist(0, words.size() - 1);

    int firstIndex = dist(rng);
    int secondIndex = dist(rng);
    while (firstIndex == secondIndex) {
        secondIndex = dist(rng);
    }

    return words[firstIndex] + words[secondIndex];
}

const std::vector<std::string>& PasswordGenerator::getWords() const {
    return words;
}
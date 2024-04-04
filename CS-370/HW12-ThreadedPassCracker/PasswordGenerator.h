//
// Created by Rako on 4/4/24.
//

#ifndef HW12_THREADEDPASSCRACKER_PASSWORDGENERATOR_H
#define HW12_THREADEDPASSCRACKER_PASSWORDGENERATOR_H


#include <string>
#include <vector>

class PasswordGenerator {
private:
    std::vector<std::string> words;
public:
    PasswordGenerator(const std::string& fileName);
    std::string generatePassword(int seed);
    const std::vector<std::string>& getWords() const;
};


#endif //HW12_THREADEDPASSCRACKER_PASSWORDGENERATOR_H

//
// Created by Rako on 1/27/24.
//

#include <iostream>
#include "mfile.h"

int main() {
    // Write example
    mFILE *writeFile = mfopen("test.txt", "w");
    if (writeFile) {
        const char *text = "Hello, world!";
        mfwrite((void *)text, sizeof(char), strlen(text), writeFile);
        mfclose(writeFile);
    }

    // Read example
    mFILE *readFile = mfopen("test.txt", "r");
    if (readFile) {
        char buffer[100];
        int bytesRead = mfread(buffer, sizeof(char), sizeof(buffer) - 1, readFile);
        if (bytesRead > 0) {
            buffer[bytesRead] = '\0';
            std::cout << "Read from file: " << buffer << std::endl;
        }
        mfclose(readFile);
    }

    // Append example
    mFILE *appendFile = mfopen("test.txt", "a");
    if (appendFile) {
        const char *text = " Appending text.";
        mfwrite((void *)text, sizeof(char), strlen(text), appendFile);
        mfclose(appendFile);
    }

    mFILE *verifyFile = mfopen("test.txt", "r");
    if (verifyFile) {
        char buffer[200];
        int bytesRead = mfread(buffer, sizeof(char), sizeof(buffer) - 1, verifyFile);
        buffer[bytesRead] = '\0';
        const char *expectedContent = "Hello, world! Appending text.";
        if (bytesRead != strlen(expectedContent) || strcmp(buffer, expectedContent) != 0) {
            std::cerr << "Content verification failed!\n";
        } else {
            std::cout << "Content verification successful.\n";
        }
        mfclose(verifyFile);
    } else {
        std::cerr << "Failed to open file for verification.\n";
    }

    // Edge Cases
    mFILE *writeModeFile = mfopen("test.txt", "w");
    if (writeModeFile) {
        char buffer[100];
        int bytesRead = mfread(buffer, sizeof(char), sizeof(buffer) - 1, writeModeFile);
        if (bytesRead < 0) {
            std::cout << "Correctly handled reading from file opened in write mode.\n";
        }
        mfclose(writeModeFile);
    }

    // Attempt to write to a file opened in read mode
    mFILE *readModeFile = mfopen("test.txt", "r");
    if (readModeFile) {
        const char *text = "Should not write this.";
        int bytesWritten = mfwrite((void *)text, sizeof(char), strlen(text), readModeFile);
        if (bytesWritten < 0) {
            std::cout << "Correctly handled writing to file opened in read mode.\n";
        }
        mfclose(readModeFile);
    }

    // Try to open a non-existent file for reading
    mFILE *nonExistentFile = mfopen("non_existent.txt", "r");
    if (!nonExistentFile) {
        std::cout << "Correctly handled opening a non-existent file for reading.\n";
    }

    return 0;
}

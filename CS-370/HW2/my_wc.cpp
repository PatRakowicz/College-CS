#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

// Function to count lines, words, and characters in file
void countFile(const string &fileName, int &lineCount, int &wordCount, int &charCount) {
    ifstream file(fileName);
    string line;
    lineCount = wordCount = charCount = 0;

    if (file.is_open()) {
        while (getline(file, line)) {
            ++lineCount;
            charCount += line.length() + 1;

            // Count words
            string word;
            istringstream lineStream(line);
            while (lineStream >> word) {
                ++wordCount;
            }
        }
    } else {
        cerr << "Cannot open file: " << fileName << endl;
    }

    file.close();
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        cerr << "Usage: " << argv[0] << " <file1> [<file2> ...]" << endl;
        return 1;
    }

    int totalLines = 0, totalWords = 0, totalChars = 0;

    for (int i = 1; i < argc; ++i) {
        int lines, words, chars;
        countFile(argv[i], lines, words, chars);
        cout << lines << " " << words << " " << chars << " " << argv[i] << endl;

        totalLines += lines;
        totalWords += words;
        totalChars += chars;
    }

    if (argc > 2) {
        cout << totalLines << " " << totalWords << " " << totalChars << " total" << endl;
    }

    return 0;
}
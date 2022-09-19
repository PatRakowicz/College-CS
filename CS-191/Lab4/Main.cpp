#include <iostream>
#include <string>

using namespace std;

int main() {

    string input = "eooyaeia";
    int count = 0;
    for (int i = 0; i < input.length(); i++) {
        if (input[i] == 'a' || input[i] == 'e' || input[i] == 'i' || input[i] == 'o' || input[i] == 'u' || input[i] == 'y')
            ++count;
    }
    cout << count << "\n";
    cout << "Printing out string Vowels and Total Count." << "\n";
}

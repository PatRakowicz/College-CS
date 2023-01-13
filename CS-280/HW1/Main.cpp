#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Download .txt and read assignment
// download example code for class
//  take file input
// create main .cpp with file input
//  Run .cpp and read/print each line from .txt

// make item struct that holds a type, status, price
// splitting each line from file around commas and putting these into a struct
//  string-stream for slitting
// create array of size 100 that holds struct, put each struct into array
// handle additional logic for adding/removing from array


struct garageSale {
    string type;
    bool status;
    double price;
};

int main() {
    string input_line;
    ifstream f("data.txt");

    if (f.is_open()) {
        cout << "Reading from file \n";
        while (getline(f, input_line)) {
            cout << input_line << endl;
        }
        f.close();
    } else {
        cout << "File does not exists \n";
    }
}
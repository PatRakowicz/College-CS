//
// Created by Livid on 13/01/2023.
//

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <tuple>
#include <utility>

using namespace std;

struct marketFormat {
    string type;
    string stat;
    bool status;
    int price;
};


int main() {
    string winFile = "m:/livid/desktop/dev/college-cs/cs-280/hw1/data.txt";
    string MacFile = "/{dir}/data.txt";

    marketFormat items[17];
    ifstream file(winFile);
    string line;
    int index = 0;

    if (!file.is_open()) {
        cout << "File does not exists \n";
        return 1;
    }

    while (getline(file, line)) {
        line.erase(remove(line.begin(), line.end(), ' '), line.end());
        replace(line.begin(), line.end(), ',', ' ');

        stringstream ss(line);

        ss >> items[index].type >> items[index].stat >> items[index].price;

        if (items[index].stat == "forsale") { items[index].status = true; }
        else { items[index].status = false; }
        index++;
    }
    file.close();

    for (int i = 0; i < index; i++) {
        cout << items[i].type << " " << boolalpha << items[i].status << " " << items[i].price << endl;
    }

    return 0;
}
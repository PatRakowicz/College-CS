//
// Created by Livid on 13/01/2023.
//

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

struct marketFormat {
    string type;
    string stat;
    bool status;
    int price;
};

vector<marketFormat> readFile(const string &fileName) {
    ifstream file(fileName);
    string line;

    vector<marketFormat> dataArray;

    if (!file.is_open()) {
        cout << "File does not exists \n";
        return {};
    }

    while (getline(file, line)) {
        line.erase(remove(line.begin(), line.end(), ' '), line.end());
        replace(line.begin(), line.end(), ',', ' ');

        stringstream ss(line);
        marketFormat data;

        ss >> data.type >> data.stat >> data.price;

        if (data.stat == "forsale") { data.status = true; }
        else { data.status = false; }
        dataArray.push_back(data);
    }
    file.close();
    return dataArray;
}

int main() {
    string winFile = "m:/livid/desktop/dev/college-cs/cs-280/hw1/data.txt";
    string MacFile = "/{dir}/data.txt";

    vector<marketFormat> dataArray = readFile(winFile);

    if (dataArray.empty()) {
        cout << "No Data / Empty Array \n";
        return 1;
    }

    /*for (int i = 0; i < dataArray.size(); i++) {
        cout << dataArray[i].type << " " << boolalpha << dataArray[i].status << " " << dataArray[i].price << endl;
    }*/

    for (auto &i: dataArray) {
        cout << i.type << " " << boolalpha << i.status << " " << i.price << endl;
    }

    return 0;
}
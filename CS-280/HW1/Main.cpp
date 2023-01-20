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

/*Vector | ReadFile given, output to a return data format for use
 *
 * @param string | Input the given file to check and read
 * @return the data structure
 * */
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

/* Check data given and remove what is equal to some others
 *
 * @param string | File input that is being read by readFile function
 * */
void checkData(string inputFile) {
    vector<marketFormat> dataArray = readFile(inputFile);

    if (dataArray.empty()) {
        cout << "No Data / Empty Array \n";
    }

    for (auto &i: dataArray) {
        cout << i.type << " " << boolalpha << i.status << " " << i.price << endl;
    }

    cout << endl << "~~~~ Checking Data ~~~~" << endl << endl;

    for (const auto& data : dataArray) {
        if(data.type == "bike") {
            cout << "Type: " << data.type;
            if(data.status) {
                cout << " | For Sale | Price:" << data.price << endl;
            } else {
                cout << " | Wanted | Price:"<< data.price << endl;
            }
        }
    }

    cout << endl << "~~~~ Checking Data ~~~~" << endl << endl;

    for (const auto& data : dataArray) {
        if(data.type == "microwave") {
            cout << "Type: " << data.type;
            if(data.status) {
                cout << " | For Sale | Price:" << data.price << endl;
            } else {
                cout << " | Wanted | Price:"<< data.price << endl;
            }
        }
    }

    cout << endl << "~~~~ Checking Data ~~~~" << endl << endl;

    for (const auto& data : dataArray) {
        if(data.type == "dresser") {
            cout << "Type: " << data.type;
            if(data.status) {
                cout << " | For Sale | Price:" << data.price << endl;
            } else {
                cout << " | Wanted | Price:"<< data.price << endl;
            }
        }
    }

    cout << endl << "~~~~ Checking Data ~~~~" << endl << endl;

    for (const auto& data : dataArray) {
        if(data.type == "truck") {
            cout << "Type: " << data.type;
            if(data.status) {
                cout << " | For Sale | Price:" << data.price << endl;
            } else {
                cout << " | Wanted | Price:"<< data.price << endl;
            }
        }
    }

    cout << endl << "~~~~ Checking Data ~~~~" << endl << endl;

    for (const auto& data : dataArray) {
        if(data.type == "chicken") {
            cout << "Type: " << data.type;
            if(data.status) {
                cout << " | For Sale | Price:" << data.price << endl;
            } else {
                cout << " | Wanted | Price:"<< data.price << endl;
            }
        }
    }

}

int main() {
    string winFile = "m:/livid/desktop/dev/college-cs/cs-280/hw1/data.txt";
    string macFile = "/Users/patrak/Documents/Dev/College-CS/CS-280/HW1/data.txt";

    checkData(macFile);

    return 0;
}
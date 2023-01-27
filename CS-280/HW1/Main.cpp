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
 * @param vector<market> | input given array of data
 * */
void checkData(const vector<marketFormat>& dataArray) {
    if (dataArray.empty()) {
        cout << "No Data / Empty Array \n";
    }

    vector<marketFormat> forSale;
    vector<marketFormat> wanted;
    vector<marketFormat> matchedItems;

    for (auto &i: dataArray) {
        if (i.status) {
            forSale.push_back(i);
        } else {
            wanted.push_back(i);
        }
    }

    for (int i = 0; i < wanted.size(); i++) {
        int j = 0;
        while (j < forSale.size()) {
            if (wanted[i].type == forSale[j].type) {
                if (wanted[i].price >= forSale[j].price) {
                    matchedItems.push_back(forSale[j]);
                    matchedItems.push_back(wanted[i]);
                    forSale.erase(forSale.begin() + j);
                    wanted.erase(wanted.begin() + i);
                    i--;
                    break;
                }
            }
            j++;
        }
    }

    cout << endl << "Sold" << endl;

    for (auto &i: matchedItems) {
        if (i.status) {
            cout << "Type: " << i.type << " Price: " << i.price << endl;
        }
//        cout << "Name: " << i.type << ", Price: " << i.price << ", Status: ";
//        cout << (i.status ? "For Sale" : "Wanted") << endl;
    }

    cout << endl << "Remaining Items" << endl;;

    for (auto &i: forSale) {
        cout << "Name: " << i.type << ", Price: " << i.price << ", Status: ";
        cout << (i.status ? "For Sale" : "Wanted") << endl;
    }
    for (auto &i: wanted) {
        cout << "Name: " << i.type << ", Price: " << i.price << ", Status: ";
        cout << (i.status ? "For Sale" : "Wanted") << endl;
    }
}

int main() {
    // change the file for the location
    // it does not work for me if I just include the file "data.txt"
    string Windows = "m:/livid/desktop/dev/college-cs/cs-280/hw1/data.txt";
    string Mac = "/Users/patrak/Documents/Dev/College-CS/CS-280/HW1/data.txt";

    string Main = "data.txt";
    checkData(readFile(Mac));

    return 0;
}
//
// Created by Livid on 1/10/2022.
//


#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main() {
    vector <string> spcBird;
    map<string, int> dupBrd;
    string n = "";

    while (n != "done") {
        cout << "Enter Bird Species: ";
        cin >> n;

        if (n != "done") { spcBird.push_back(n); }
    }

    for (auto & i : spcBird) {
        auto result = dupBrd.insert(pair<string, int>(i, 1));
        if (!result.second) { result.first->second++; }
    }

    cout << "Here are the species you entered: " << endl;
    for (auto &i: spcBird) {
        cout << i << endl;
    }

    cout << endl;

    cout << "All Birds: " << endl;
    for (auto &i: dupBrd) {
        if (i.second > 1) {
            cout << "species: " << i.first << ", count:" << i.second << endl;
        }
    }

}


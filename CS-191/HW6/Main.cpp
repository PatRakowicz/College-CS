//
// Created by Livid on 1/10/2022.
//


#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    vector <string> spcBird;
    vector <string> dupBrd;
    string n = "";

    while (n != "done") {

        cout << "Enter Bird Species: ";
        cin >> n;

        for (auto & i : spcBird) {
            if (n == i) {
                dupBrd.push_back(n);
                cout << "~~Duped Input~~" << endl;
            }
        }
        if (n != "done") { spcBird.push_back(n); }
    }

    cout << "Here are the species you entered: " << endl;
    for (auto &i: spcBird) {
        cout << i << endl;
    }

    cout << "Duped Birds Entered: " << endl;
    for (auto &i: dupBrd) {
        cout << i << endl;
    }

}


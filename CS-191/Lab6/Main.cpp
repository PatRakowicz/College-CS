//
// Created by mo on 9/28/22.
//
// creat a structure to store dog names, Unknown amount of name
// keep promping the user for another dog bread until done
// if dog breed is already inputted, give error, if not add to end of list
// after "done" print all names in array


#include <iostream>
#include <string>
#include <vector>

using namespace std;
int main() {
    vector<string> dog_breed;
    string n = "";
    int rem_dupe = 0;
    string removed;
    bool duplicate;

    while (n != "done") {
        cout << "Enter dog breed: ";
        cin >> n;
        duplicate = false;
        for (int i = 0; i < dog_breed.size(); i++) {
            if (n == dog_breed[i]) {
                duplicate = true;
                cout << "~~Duped Input~~" << endl;
            }
        }

        if (n != "done" && !duplicate) { dog_breed.push_back(n);}
    }

    cout << "Here are the breeds you entered: " << endl;
    for (auto & i : dog_breed) {
        cout << i << endl;
    }

}

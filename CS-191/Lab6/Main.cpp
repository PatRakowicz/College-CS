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
    string n;
    bool is_dupe;
    int rem_dupe = 0;

    while (n != "done") {
        cout << "Enter dog breed: ";
        cin >> n;
        for (int i = 0; i < dog_breed.size(); i++) {
            if (n == dog_breed[i]) {
                is_dupe = true;
                rem_dupe = i;
            }
        }

        if (n != "done") { dog_breed.push_back(n);}
    }

    cout << "Here are the breeds you entered: " << endl;
    for (int i = 0; i < dog_breed.size(); i++) {
        cout << dog_breed[i] << endl;
    }

}

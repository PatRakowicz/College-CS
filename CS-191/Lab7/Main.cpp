//
// Created by Rako on 10/4/22.
//

/*
Given an array of integers (you can hard code the array, you do not need to get user input),
 your goal is to determine if any 2 distinct integers in the array sum to a target integer t.

 1. You must write a function called sums that accepts an integer array, an integer length of the array,
 and an integer that returns true if 2 distinct numbers in the array sum to tand false otherwise.

 2. You must comment on the functionality, parameters, and return types of your functions
 above each function in a multi-line comment.

 3. You must test this function on at least 3 different arrays/targets and show me the output.
*/

#include <iostream>
#include <random>

using namespace std;

int sum(int *arr, int T) {
    int sum = 0;

    // grab 2 rand elemnt from array
    int random = rand() % 6;
    int random2 = rand() % 6;

    int getArrLen = sizeof(arr)/ sizeof(int);

    int first = arr[random];
    int second = arr[random2];

    cout << "First Second";
    cout << first << " " << second << endl;

    // check if two ints are = to T (mainT)
    int last = first + second;
    if (last == T) {
        cout << "if = " << last << endl;
    } else {
        cout << "False" << endl;
    }
    // if 2 = to T, print
    // else 2 != to T, repeat

    for (int i = 0; i < getArrLen; i++) {
        sum += arr[i];
    }
    return sum;
}

int main() {
    int mainArr[]  = {11, 22, 5, 25, 15, 3,};
    int size = 6;
    int mainT = 44;

    cout << "func Sum : " << sum(mainArr, size) << endl;

    cout << "main arr out : " << endl;
    for (auto &i: mainArr) {
        cout << i << endl;
    }

    cout << "Main T: " << mainT << endl;
}

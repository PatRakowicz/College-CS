//
// Created by Rako on 10/4/22.
//

/*
Given an array of integers (you can hard code the array, you do not need to get user input),
 your goal is to determine if any 2 distinct integers in the array sum to a target integer t.

 1. You must write a function called sums that accepts an integer array, an
    integer length of the array, and an integer t that returns true if 2 distinct
    numbers in the array sum to t and false otherwise

 2. You must comment on the functionality, parameters, and return types of your functions
    above each function in a multi-line comment.

 3. You must test this function on at least 3 different arrays/targets and show me the output.
*/

#include <iostream>

using namespace std;

/*
 * True | False | check array for any two ints that add up to T
 *
 * @param arr | Input Array given
 * @param size | Input size of given array
 * @param t | Input given value to check
 * @return True | if arr[x + y] = t
 * */

bool sums(int *arr, int size, int t) {
    for (int i = 0; i < size; i++) {
        for (int e = i + 1; e < size; e++) {
            if (arr[i] + arr[e] == t) {
                cout << "I & E: " << i << " " << e << endl;
                return true;
            }}}
    return false;
}

int main() {
    const int length = 6;
    int mainArr[length] = {23, 12, 15, 22, 32, 8};
    int t = 20;

    cout << boolalpha << sums(mainArr, length, t) << endl;
}

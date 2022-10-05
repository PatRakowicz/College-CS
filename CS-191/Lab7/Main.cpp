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
 * input array, check if two possible integers are sum to t int
 *
 * @param arr the main array that is inputted
 * @param size the size of the main array
 * @param t the input of sum that needs to add to it
 * @return the sum of the number and if true or false
 */
int sum(int *arr, int size, int t) {
    int sum = 0;
    for(int i = 0; i < size; i++) {
        if()
    }
}

int main() {
    int mainArr[size]  = {1, 2, 3};
    int size = 3;
    int t = 44;

    cout << "func Sum : " << sum(mainArr, size) << endl;

    cout << "main arr out : " << endl;
    for (auto &i: mainArr) {
        cout << i << endl;
    }

    cout << "Main T: " << t << endl;
}

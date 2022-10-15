//
// Created by mo on 10/12/22.
//

#include <iostream>

using namespace std;

/**
 * Tests to see whether any two ints in array sum to t
 *
 * @param array | the list we are testing for a palindrome
 * @param n | the (remaining) length of the array
 * @param left | the index on the left that im checking
 * @param right | the index on the right that im checking
 * @return true | if the array is an integer palindrome, false otherwise
 */
bool palindrome(string x, int left, int right) {
    if (left == right) {
        return true;
    } else if (left < right) {
        if (x[left] == x[right])
            return true;
    } else if (x[left] == x[right])
        return palindrome(x, left + 1, right + 1);
    return false;
}

/*
 * Return value with two inputs
 *
 * @param x | Input number to be multiplied
 * @param y | Input number multiplier
 * @return int | Output the given number from math done
 * */
int multi(int x, int y) {
    if (y == 0) {
        return 0;
    }
    return x + multi(x, y - 1);
}

int main() {
    cout << boolalpha << palindrome("aba", 0, 2) << endl;
    cout << boolalpha << palindrome("aabbaa", 0, 5) << endl;
    cout << boolalpha << palindrome("hello", 0, 4) << endl;
    cout << boolalpha << palindrome("hannah", 0, 5) << endl;

    cout << endl;
    cout << multi(5, 4) << endl;
    cout << multi(10, 3) << endl;

    return 0;
}
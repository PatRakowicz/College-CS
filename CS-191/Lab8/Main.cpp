#include <iostream>
#include <vector>

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
bool even_palindrome(int *arr, int l, int left, int right) {
    if (l == 2) { return arr[left] == arr[right]; }

    if (arr[left] != arr[right]) {
        return false;
    } else {
        return even_palindrome(arr, l - 2, left + 1, right - 1);
    }
}

int main() {
    int length = 6;
    int x[] = {1, 2, 3, 3, 2, 1};
    cout << boolalpha << even_palindrome(x, length, 0, length - 1);
    return 0;
}
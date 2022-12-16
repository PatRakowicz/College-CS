#include <iostream>

using namespace std;

/**
sum up all the integers in a list

@param arr: the array to sum up integers from
@param length: the elnthg of the array
@return the sum of all elements in the array, 0 if array is empty
*/

int sum(int *arr, int length) {

    int s = 0;
    for (int i = 0; i < length; i++)
        s += arr[i];
    return s;
}


int main() {
    cout << "--- Testing sum Function ---" << endl;
    // boundary testing
    int x[0];
    int length = 0;
    if (sum(x, length) != 0)
        cout << "ERROR: incorrect solution when length = 0 \n";
    // test passed

    // test boundary + 1 ( one element )
    int x2[1] = {1};
    int length2 = 1;
    if (sum(x2, length2) != 1)
        cout << "ERROR: incorrect solution when length = 1 \n";

    // tst arbitrary case ( some elements > 1 )
    int x3[5] = {1, 5, 2, 6, 3};
    int length3 = 5;
    if (sum(x3, length3) != 17)
        cout << "ERROR: Incorrect solution with 5 elements \n";
}
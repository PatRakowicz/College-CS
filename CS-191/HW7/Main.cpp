//
// Created by mo on 10/7/22.
//

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
bool sums(int *array, int size, int t) {
    for (int i = 0; i < size - 1; i++) {
        for (int e = i; e < size; e++) {
            for (int f = e; f < size; f++) {
                if (array[i] + array[e] + array[f] == t) {
                    cout << "I & E & F: " << i << " " << e << " " << f << endl;
                    return true;
                }
            }
        }
    }
    return false;
}

/*
 * Modify given array, Double all values in array, Triple value t
 *
 * @param array | Pass by reference to given array
 * @param size | Input size of array
 * @param t | Input T value for calculations
 * */
void modify(int &array, int size, int &t) {

}

/*
 * Given array, Print
 *
 * @param array | Input given array
 * @param size | Input given size array
 * @return Output elements in array
 * */
int prt_arr(int array, int size) {

}

int main() {
    const int length = 6;
    int mainArr[length] = {23, 12, 15, 22, 32, 8};
    int t = 35;

    cout << boolalpha << sums(mainArr, length, t) << endl;
}
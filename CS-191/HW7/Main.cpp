//
// Created by mo on 10/7/22.
//

#include <iostream>
#include <vector>

using namespace std;


/*
 * True | False | check array for any two ints that add up to T
 *
 * @param arr | Input Array given
 * @param size | Input size of given array
 * @param t | Input given value to check
 * @return True | if arr[x + y] = t
 * */
bool sums(const int *array, int size, int t) {
    for (int i = 0; i < size - 1; i++) {
        for (int e = i; e < size; e++) {
            for (int f = e; f < size; f++) {
                if (array[i] + array[e] + array[f] == t) {
//                    cout << "I & E & F: " << i << " " << e << " " << f << endl;
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
void modify(int *array, int &t, int size) {
    for (int i = 0; i < size; i++) {
        array[i] *= 2;
    }

    t *= 3;
}

/*
 * Given array, Print
 *
 * @param array | Input given array
 * @param size | Input given size array
 * */
void prt_arr(int *array, int size) {
    for (int i = 0; i < size; i++) {
        cout << array[i] << ' ';
    }
    cout << endl;
}

int main() {
    const int length = 6;
    int mainArr[length] = {2, 6, 15, 22, 32, 2};
    int t = 10;

    cout << "Print Array: ";
    prt_arr(mainArr, length);
    cout << "Target: " << t << endl;

    if (sums(mainArr, length, t)) {
        cout << "It Works!" << endl;
        modify(mainArr, t, length);
    } else { cout << "It No Work" << endl; }

    cout << endl;

    cout << "Print Array: ";
    prt_arr(mainArr, length);
    cout << "Target: " << t << endl;

    if (sums(mainArr, length, t))
        { cout << "It Works!" << endl; }
    else { cout << "It No Work" << endl; }



}
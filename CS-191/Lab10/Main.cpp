//
// Created by mo on 10/26/22.
//
#include <iostream>

using namespace std;

/**
 * Swap two values in the array
 *
 * @param arr | Input given array to want swap ints
 * @param i | Input first value int
 * @param j | Input second value
 */
void arrSwapInt(int *arr, int i, int j) {
    j = arr[i];
    arr[i] = arr[i + 1];
    arr[i + 1] = j;
}

/**
 * Bubble sort, take one int and check the array for a smaller value
 * if value is smaller move to the front
 *
 * @param arr | Input the array to be sorted
 * @param size | Input the size of given array
 */
void bubble_sort(int *arr, int size) {
    for (int pos = 0; pos < size; pos++) {
        for (int i = 0; i < size - pos; i++) {
            if (arr[i] < arr[i + 1]) {
                arrSwapInt(arr, i, i + 1);
            }
        }
    }
}


int main() {
    int x[5] = {1, 4, 6, 5, 8};
    bubble_sort(x, 5);
    for (int i: x) {
        cout << i << endl;
    }

}

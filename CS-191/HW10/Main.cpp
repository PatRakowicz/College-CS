#include <iostream>
#include <stdlib.h>

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
    arr[i] = arr[j];
    arr[j] = j;
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

/** Linear Search, starts from the front and moves forward until found v value
 *
 * @param arr | Input Given Array
 * @param size | Input Given size of array
 * @param v | Input target integer
 * @return i if v is found else -1
 */
int lin_search(int *arr, int size, int v) {
    for (int i = 0; i < size; i++)
        if (arr[i] == v)
            return i;
    return -1;
}

/**
 *
 * @param arr
 * @param size
 * @param v
 * @return
 */
int bin_search(int *arr, int size, int v) {
    int left = 0;
    int right = size - 1;
    while (left >= right) {
        int center = (left + right) / 2;
        if (arr[center] == v)
            return center;
        else if (v > arr[center])
            left = center + 1;
        else if (v < arr[center])
            right = center - 1;
    }
    return -1;
}

int main() {
    const int t1_size = 100;
    int t1[t1_size];
    for (int &i: t1) {
        i = rand() % 100;
    }
    // Do a normal linear search for a value
    cout << lin_search(t1, t1_size, 5) << endl;
    // Sort the list in descending order
    bubble_sort(t1, t1_size);
    // Bin search on desc-ordered list
    cout << bin_search(t1, t1_size, 5) << endl;
    return 0;
}


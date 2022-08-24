//
// Created by Livid on 29/03/2022.
//
// Example of bubble Sort from an array, sort from the least value to max value;

#include <iostream>

using namespace std;

const int MAX = 10;

void swap(int &a, int &b) {         //swap
    int temp = a;
    a = b;
    b = temp;
}

void bubbleSort(int x[]) {      // BubbleSort
    for (int pass = 0; pass < MAX - 1; pass++) {            // Pass
        for (int pos = 0; pos < MAX - 1 - pass; pos++) {    // Pos
            if (x[pos] > x[pos + 1])
                swap(x[pos], x[pos + 1]);
        }
    }
}

void display(int x[MAX]) {      // List Display
    for (int i = 0; i < MAX; i++)
        cout << x[i] << "  ";
    cout << endl;
}

int main() {
    cout << "Displayed Unsorted" << "\n";
    int m[MAX] = {-8, 45, 22, 76, 51, 22, -30, 85, 33, 12};
    display(m);
    bubbleSort(m);
    cout << "Displayed Bubble Sorted" << "\n";
    display(m);
}
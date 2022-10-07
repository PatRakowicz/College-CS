//
// Created by mo on 10/7/22.
//

#include <iostream>

using namespace std;

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

int main() {
    const int length = 6;
    int mainArr[length] = {23, 12, 15, 22, 32, 8};
    int t = 35;

    cout << boolalpha << sums(mainArr, length, t) << endl;
}
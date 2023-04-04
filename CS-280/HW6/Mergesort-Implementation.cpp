/*
 * Patrick Rakowicz
 * Merge Sort Algorithm
 * */

#include <iostream>
#include <vector>

using namespace std;

void maxHeapify(vector<int>& A, int x) {
    int left = 2 * x + 1;
    int right = 2 * x + 2;
    int largest = x;

    if (left < A.size() && A[left] > A[largest])
        largest = left;

    if (right < A.size() && A[right] > A[largest])
        largest = right;

    if (largest != x) {
        swap(A[x], A[largest]);
        cout << "Array after swap: ";
        for (int num : A)
            cout << num << " ";
        cout << endl;
        maxHeapify(A, largest);
    }
}

void buildHeap(vector<int>& A) {
    for (int x = A.size() / 2 - 1; x >= 0; x--) {
        maxHeapify(A, x);
        cout << "Array after maxHeapify: ";
        for (int num : A)
            cout << num << " ";
        cout << endl;
    }
}

int main() {
    vector<int> A = {5, 10, 3, 2, 5, 80, 15, 72};
    vector<int> B = {10, 3, 2, 13, 14, 5, 6, 40, 34, 7};

    buildHeap(B);

    for (int num : B)
        cout << num << " ";

    return 0;
}
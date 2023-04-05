#include <iostream>
#include <vector>

using namespace std;

void printArray(vector<int>& arr) {
    for (int i : arr)
        cout << i << " ";
    cout << endl;
}

void merge(vector<int>& arr, int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    vector<int> L(n1), R(n2);

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int>& arr, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        cout << "Dividing array from index " << l << " to " << r << ": ";
        printArray(arr);
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
        cout << "Merging arrays from index " << l << " to " << r << ": ";
        printArray(arr);
    }
}

int main() {
    vector<int> arr = {4, 22, 98, 1, 18, 15, 3, 91, 72, 5, 9, 34, 2, 17, 46, 55};
    int n = arr.size();

    cout << "Original array: ";
    printArray(arr);

    mergeSort(arr, 0, n - 1);

    cout << endl << "Sorted array: ";
    printArray(arr);

    return 0;
}

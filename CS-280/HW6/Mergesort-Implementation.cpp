#include <iostream>
using namespace std;

void merge (int*, int, int, int);
void mergeSort(int* arr, int min, int max) {

	int mid;
	if (min < max) {
		mid = (min + max) /2;
		
		mergeSort(arr, min, mid);
		mergeSort(arr, mid + 1, max);
		merge(arr, min, max, mid);
	}
}

void merge (int* arr, int min, int max, int mid) {
	int i, j, k, c[50];
	i = min;
	k = min;
	j = mid + 1;

	while (i <= mid && j <= max) {
		if (arr[i] < arr[j] {
			c[k] = arr[i];
			k++;
			i++;
		} else {
			c[k] = arr[j];
			k++;
			j++;
		}
	}

	while (i <= mid) {
		c[k] = arr[i];
		k++;
		i++;
	}

	for (i = min; i < k; i++) { arr[i] = c[i]; }
}

int main() {
	int array[30], num;

	cout << "Enter % of elements in array: ";
	cin >> num;
	cout << "Enter " << num << " elements to be stored: ";

	for (int i = 0; i < num; i++) { cin >> array[i]; }

	mergeSort (array, 0, num - 1);
	cout << "Sorted array:\n";
	
	for ( int i = 0; i < num; i++) { cout << array[i] << " "; }
}		

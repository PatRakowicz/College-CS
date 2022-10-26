#include <iostream>
#include <string>

using namespace std;

/**
 * Selection Sort on array L | Modifies L to be in acending order
 *
 * @param L | the array that will be sorted (pass by ref)
 * @param length | the number f elements in L
 */
void selection_sort( int *L, int leng) {
	for (int i = 0; i < leng; i++) {
		int min_index = i;
		for(int j = i+1; j < leng; j++) {
			if(L[j] < L[min_index]) {
				min_index = j;
			}
		}
		int temp = L[i];
		L[i] = L[min_index];
		L[min_index] = temp;
	}
}

int main() {
	int x[5] = {5,1,52,13,23};
	selection_sort(x, 5);
	for (int i = 0; i < 5; i++){
		cout << x[i]<< endl;
	}
}

// Write a function that computes the average number in an array of integers
// one where the soution is returned
// one version where the solution is stored in a reerenced variable
// write a function that makes every number in a list odd
// doc both unctions

#include <iostream>
#include <string>

using namespace std;

/** 
 * function to return the average value of an integer array
 *
 * @param my_arr integer array in consideration
 * @param length the number of elements in my_arr
 * @return the double value average
 */

double ret_avg(int *my_arr, int length) {
	int solution = 0;
	
	for(int i = 0; i < length; i++) {
		solution += my_arr[i];
	}
	return (double)solution / (double)length; 
}

/**
 * Compute average of array of integers and store result in variable
 *
 * @param my_arr the array we will average
 * @param length the number of elements in my_arr
 * @param solution the variable where the solution will be stored
 */

void ref_avg(int *my_arr, int length, double &solution) {
	solution = 0;
	for (int i = 0; i < length; i++) {
		solution += my_arr[i];
	}
	solution = solution / length;
}

/*
 * Modify integer array so that every vale is odd by adding one to even values
 *
 * @param arr the array of integers
 * @param length the number of elements in arr
 */
void make_odd(int * arr, int length) {
	for(int i = 0; i < length; i++){
		if(arr[i] % 2 == 0) {
			arr[i]++;
		}
	}
}

int main() {
	
	const int length = 5;
	int x[length] = {2, 5, 73, 23, 59};
	double average = ret_avg(x, length);
	cout << average << endl;

	double sol;
	ref_avg(x, length, sol);
	cout << sol << endl;
	
	const int length_two = 7;
	int mixed[length_two] = {1, 2, 3, 4, 5, 6, 7};
	make_odd(mixed, length_two);
	for (int i = 0; i < length_two; i++) {
		cout << mixed[i] << " ";
	}
	cout << endl;

	return 0;
}

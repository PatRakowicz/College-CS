//
// Created by Patrick Rakowicz on 29/09/2023.
//
#include <iostream>
#include <time.h>

const int ARRAY_SIZE = 100000;
const int CALL_TIMES = 1000000;

void func_stack() {
	int arr[ARRAY_SIZE];
	arr[0] = 0;
}

void func_dyn() {
	int* arr = new int[ARRAY_SIZE];
	arr[0] = 0;
	delete[] arr;
}

void func_static() {
	static int arr[ARRAY_SIZE];
	arr[0] = 0;
}

int main() {
	clock_t	start, end;

	start = clock();
	for (int i = 0; i < CALL_TIMES; i++) func_stack();
	end = clock();
	std::cout << "FUNC_STACK: " << end - start << std::endl;

	start = clock();
	for (int i = 0; i < CALL_TIMES; i++) func_dyn();
	end = clock();
	std::cout << "FUNC_DYN: " << end - start << std::endl;

	start = clock();
	for (int i = 0; i < CALL_TIMES; i++) func_static();
	end = clock();
	std::cout << "FUNC_STATIC: " << end - start << std::endl;
}

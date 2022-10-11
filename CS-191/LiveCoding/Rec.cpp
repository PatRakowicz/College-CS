#include <iostrea>
#include <string>

using namespace std;


/*
 * Gies user 1+2+...+n
 *
 * @param n the nmber to sum to
 * @return the sum of 1->m
 */

int sum_up(int n) {
	if (n == 1) {
		return 1;
	}
	return n + sum_up(n-1);
}

/**
 * Computes nth Fibinacci number
 *
 * @param n the argument to the fibonacci squence
 * @return nth fubonacci number
 */
int fib(int n) {
	if (n == 0 || n ==1) {
		return 1;
	}
	return fib(n-1) + fib(n-2);
}

in main () {
	cout << sum_up(5) << endl;
	cout << fib(5) << endl;

	return 0;
}

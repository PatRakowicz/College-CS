#include <stdio.h>

// Define the struct for rational numbers
typedef struct rational {
	int numerator;
	int denominator;
} Rational;

// Function to calculate the greatest common divisor
int gcd(int a, int b) {
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

// Method to multiply two rational numbers without reducing the result
Rational mult(Rational r1, Rational r2) {
	Rational result;
	result.numerator = r1.numerator * r2.numerator;
	result.denominator = r1.denominator * r2.denominator;
	return result;
}

// Method to check if two rational numbers are equal without reducing
int equals(Rational r1, Rational r2) {
	return (r1.numerator * r2.denominator) == (r1.denominator * r2.numerator);
}

// Method to display a rational number without reducing
void display(Rational r) {
	printf("(%d/%d)\n", r.numerator, r.denominator);
}

// Test the implementation with the main function
int main() {
	Rational a = {1, 2};
	Rational b = {2, 9};
	Rational c = mult(a, b);
	display(a);
	display(b);
	display(c);
	Rational d = {2, 18};
	printf("%d\n", equals(c, d));
	return 0;
}

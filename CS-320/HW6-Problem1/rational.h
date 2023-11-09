#ifndef RATIONAL_H
#define RATIONAL_H

#include <stdexcept>
#include <iostream>

using namespace std;


class rational {
private:
	int numerator;
	int denominator;

public:
	rational() : numerator(0), denominator(1) {}

	rational(int num, int den) : numerator(num), denominator(den) {
		if (denominator == 0) {
			throw invalid_argument("Denominator cannot be zero.");
		}
	}

	int getNum() const {
		return numerator;
	}

	int getDen() const {
		return denominator;
	}

	rational mult(const rational &other) const {
		return rational(numerator * other.numerator, denominator * other.denominator);
	}

	bool equals(const rational &other) const {
		return numerator * other.denominator == denominator * other.numerator;
	}

	void display() const {
		cout << "(" << numerator << "/" << denominator << ")" << endl;
	}
};

#endif // RATIONAL_H

#include <iostream>
#include "rational.h"
using namespace std;

int main() {
	rational a(7, 9);
	a.display();
	rational b(8, 10);
	b.display();
	rational c = a.mult(b);
	c.display();
	cout << a.equals(b) << endl;
	rational d(7, 9);
	cout << a.equals(d) << endl;
	rational e;
	e.display();

	return 0;
}
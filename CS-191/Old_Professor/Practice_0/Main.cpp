/*
    191
    practice0
    main.cpp
    Patrick Rakowicz
*/

#include <iostream>
using namespace std;

int main() {
    int m1, m2, difference, product, average;
    double sum, daver;

    cout << "Please input 2 integers:";
    cin >> m1 >> m2;

    sum = m1 + m2;
    difference = m1 - m2;
    product = m1 * m2;
    average = sum / 2;
    daver = sum / 2;

    cout << "Sum: " << sum << " Difference: " << difference << " Product: " << product << endl;
    cout << "Integer average: " << average << endl;
    cout << "Double average: " << daver << endl;
}

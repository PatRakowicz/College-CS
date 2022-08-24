/*
    191
    For Loop Practice
    main.cpp
    Patrick Rakowicz
*/
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    // Loop 1
    int m1, n1, count;
    float sum = 0;

    cout << "Generating Numbers from m to n" << endl;
    cout << "Enter m and n:";
    cin >> m1 >> n1;

    cout << "Expected: Integers from " << m1 << " to " << n1 << endl;
    count = n1 - m1 + 1;

    cout << "Actual: ";
    for (int i = m1; i < (n1 + 1); ++i) {
        cout << i << " ";
        sum += i;
    }
    cout << endl;
    cout << setprecision(2) << fixed << "Sum: " << double (sum) << " " << "Average: " << double (sum/count) << endl;

    cout << endl;

    // Loop 2
    int m2, n2, a, b;

    cout << "Generating Numbers from m to n" << endl;
    cout << "Enter m and n:";
    cin >> m2 >> n2;

    if (m2 > n2) {
        a = n2;
        b = m2;
    } else {
        a = m2;
        b = n2;
    }

    cout << "Expected: odd integers from " << a << " to " << b << endl;
    cout << "Actual: ";

    for (int i = a; i < (b + 1); ++i) {
        if (i % 2 != 0) {
            cout << i << " ";
        }
    }
}
/*
    191
    Practice 1
    main.cpp
    Patrick Rakowicz | Caleb Domenico
*/
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;


int main() {
    int m1, m2;
    srand(time(NULL));

    cout << "Input two integers in increasing order:";
    cin >> m1 >> m2;

    float value, maxVal = m1, minVal = m2;
    float sum = 0;

    cout << "Generating random integers" << endl;
    cout << "Expected:" << endl;
    cout << "10 Random integers in the range [" << m1 << " , " << m2 << "]" << endl;

    for (int i=1; i<=10;i++) {
        value = (rand() % (m2 - m1 + 1));
        cout << value << " ";
        sum += value;
        if (value < minVal) {
            minVal = value;
        } else if (value > maxVal) {
            maxVal = value;
        }
    }
    cout << endl;

    cout << "Expected:" << endl;
    cout << "average value of the integers" << endl;
    cout << "maximum value of the integers" << endl;
    cout << "minimum value of the integers" << endl;
    cout << "Actual:" << endl;
    cout << double (sum/10) << endl;
    cout << double (maxVal) << endl;
    cout << double (minVal) << endl;
}

/*
    191
    Loop Practice 2
    main.cpp
    Patrick Rakowicz
*/

#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    // Loop 1
    int  input, count = 0;
    float maxVal = 100, minVal = 0;
    double sum = 0;

    while (true) {
        count = count + 1;
        cout << "Enter a positive value:";
        cin >> input;
        sum += input;

        if (input > maxVal)
            maxVal = input;
        if (input < minVal)
            minVal = input;

        if (sum > 100 || input == 0)
            break;
    }

    cout << "Max Value: " << maxVal << endl;
    cout << "Min Value: " << minVal << endl;
    cout << "Average Value: " << setprecision(1) << fixed << sum / count << endl;

    // Loop 2

    int input2, count2 = 0, maxVal2 = 0, minVal2 = 0;
    int posSum = 0, negSum = 0;
    float sum2 = 0;

    while (true) {
        count2 = count2 + 1;
        cout << "Enter a value: ";
        cin >> input2;

        if (input2 >= 0) {
            posSum += input2;
        } else if (input2 < 0) {
            negSum += input2;
        }

        if (input2 > maxVal2) {
            maxVal2 = input2;
        }
        if (input2 < minVal2) {
            minVal2 = input2;
        }

        if (sum2 > 100 || input2 == 0)
            break;
    }
    sum2 = float(posSum) + float(negSum);
    cout << "Sum: " << sum2 << endl;
    cout << "Max Value: " << maxVal2 << endl;
    cout << "Min Value: " << minVal2 << endl;
    cout << "Average Value: " << setprecision(1) << fixed << sum2 / float(count2) << endl;
}
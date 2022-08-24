/*
    191
    Quadratic File
    main.cpp
    Patrick Rakowicz
*/
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

void greeting() {
    cout << "Hello User, Welcome to the Quadratic Calculator..." << endl;
    cout << "This will read from a file..." << endl;
}

void readFile(float &a, float &b, float &c, ifstream &file) {
    file >> a >> b >> c;
}

double disc(double a, double b, double c) {
    double r = b * b - 4 * a * c;
    return r;
}

double calcRoot1(double a, double b, double c) {
    double x1 = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
    return x1;
}

double calcRoot2(double a, double b, double c) {
    double x2 = (-b - sqrt(b * b - 4 * a * c)) / (2 * a);
    return x2;
}

int main() {

    greeting();
    ifstream dataFile("data.txt");

    float a, b, c;
    double root1, root2;

    while (!dataFile.eof()) {
        readFile(a, b, c, dataFile);

        if (disc(a, b, c) >= 0) {
            root1 = calcRoot1(a, b, c);
            root2 = calcRoot2(a, b, c);
            cout << "The roots are | " << root1 << " and " << root2 << endl;
        } else {
            cout << "There are no real roots" << endl;
        }
    }
    dataFile.close();
}


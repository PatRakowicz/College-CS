/*
    Patrick Rakowicz
    CS 191
    main.cpp
    Rational 1

Write a single file program to prototype, define and then test a class for rational numbers.
Recall that a rational number is a number in the form a/b, where a, b are integers and b is not 0. Examples: 2/3, -8/5, 0/20
*/

#include <iostream>

using namespace std;

class Rational {
private:
    int num, den;
public:
    Rational() {
        num = 0;
        den = 1;
    };

    Rational(int n, int d) {
        num = n;
        if (d == 0) {
            cout << "Error! ~ Has to be greater then 0 ~" << "\n";
            exit(1);
        } else
            den = d;
    };

    void load();

    void display();

    void set(int, int);

    int getDen();

    int getNum();

    double getApprox();

    void add(Rational);

    void sub(Rational);

    void multi(Rational);

    void div(Rational);

    friend Rational add(Rational, Rational);

    friend bool equal(Rational, Rational);
};

void Rational::load() {
    cout << "Enter Num / Den: ";
    cin >> num >> den;
}

void Rational::display() {
    cout << num << " | " << den << "\n";
}

void Rational::set(int n, int d) {
    num = n;
    if (d == 0) {
        cout << "Error! ~ Has to be greater then 0 ~" << "\n";
        exit(1);
    } else
        den = d;
}

int Rational::getDen() {
    return den;
}

int Rational::getNum() {
    return num;
}

double Rational::getApprox() {
    return (double) num / (double) den;
}

void Rational::add(Rational r) {
    int n = num * r.den + r.num * den;
    int d = den * r.den;
}

void Rational::sub(Rational r) {
    int n = num * r.den - r.num * den;
    int d = den * r.den;
}

void Rational::multi(Rational r) {
    int n = num * r.num;
    int d = den * r.den;

    set(n, d);
}

void Rational::div(Rational r) {
    int n = num * r.den;
    int d = den * r.num;
}

Rational add(Rational r1, Rational r2) {
    Rational res;
    int n = (r1.num) * (r2.den) + (r2.num) * (r1.den);
    int d = (r1.den) * (r2.den);

    res.set(n, d);
    return res;
}

bool equal(Rational r1, Rational r2) {
    return (r1.num * r2.den == r2.num * r1.den);
}

int main() {
    Rational test1(2, 3);
    Rational test2(-8, 5);
    Rational test3(0, 20);
    Rational test4 = Rational();
    Rational test5 = Rational();

    test4.set(5, 8);
    test4.display();

    test5.load();
    test5.display();

    cout << test1.getNum() << "\n";
    cout << test2.getDen() << "\n";
    cout << test3.getApprox() << "\n";

    test1.add(test2);
    cout << test1.getNum() << " | " << test1.getDen() << "\n";

    test1.sub(test3);
    cout << test1.getNum() << " | " << test1.getDen() << "\n";

    test1.multi(test1);
    cout << test1.getNum() << " | " << test1.getDen() << "\n";

    test1.div(test1);
    cout << test1.getNum() << " | " << test1.getDen() << "\n";

    Rational r4 = add(test1, test2);
    cout << r4.getNum() << " | " << r4.getDen() << "\n";

    cout << boolalpha << equal(test1, test2) << "\n";
}

//
// Created by mo on 11/2/22.
//

#include <iostream>
#include <string>

using namespace std;

class vehicle {
private:
public:
    string make;
    string model;
    int year;
    float price;
    int miles;

    vehicle();

    vehicle(string make, string model, int year, float price, int miles);

    void print();
};

vehicle::vehicle() {
    make = "Toyota";
    model = "Prius";
    year = 2020;
    price = 25000;
    miles = 1000;
}

vehicle::vehicle(string make, string model, int year, float price, int miles) {
    this->make = make;
    this->model = model;
    this->year = year;
    this->price = price;
    this->miles = miles;
}

void vehicle::print() {
    cout << "Make: " << make << endl;
    cout << "Model: " << model << endl;
    cout << "Year: " << year << endl;
    cout << "Price: " << price << endl;
    cout << "Miles: " << miles << endl;
}

int main() {
    vehicle c1;
    c1.print();
    cout << endl;
    vehicle c2("Ford","Focus",2002,3000,150000);
    c2.print();
    return 0;
}
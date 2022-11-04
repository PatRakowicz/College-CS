//
// Created by Livid on 4/11/2022.
//

/*
 You will be using your Vehicle object from Lab 11 (see the lab for more details)
and building some additional functionality into the class. Any member functions
 added must be declared in the class and implemented below as
demonstrated in class. Moreover, you must document your member
functions with a description, parameters, return values, etc.. You must
add the following member functions to your vehicle class:

1. Add a private string variable called notes that gets set to the empty string
in every constructor.

2. Add a member function called compare cost that accepts another vehicle
and returns true if the current vehicle is worth more than the other and
false otherwise.

3. Add another constructor that accepts make, model, and year and sets cost
to $0, mileage to 0, and notes to “” by default.

4. Add a member function called add note that accepts a string and returns
void. This function should append a new note onto the notes variable on
a new line.

5. Add a member function called print notes that accepts no parameters
and returns void. This function should simply print out the notes about
the vehicle.
 */

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
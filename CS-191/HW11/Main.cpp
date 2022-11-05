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
#include <vector>

using namespace std;

class vehicle {
private:
    vector<string> notes;
public:
    string make;
    string model;
    int year;
    float price;
    int miles;

    vehicle();

    vehicle(string make, string model, int year);

    vehicle(string make, string model, int year, float price, int miles);

    bool compareCost(const vehicle &a) const;

    void print();

    void print_notes();

    void add_note(string notes);
};

vehicle::vehicle() {
    make = "Toyota";
    model = "Prius";
    year = 2020;
    price = 25000;
    miles = 1000;
    notes.emplace_back("");
}

vehicle::vehicle(string make, string model, int year) {
    this->make = make;
    this->model = model;
    this->year = year;
    price = 0;
    miles = 0;
    this->notes.emplace_back("");
}

vehicle::vehicle(string make, string model, int year, float price, int miles) {
    this->make = make;
    this->model = model;
    this->year = year;
    this->price = price;
    this->miles = miles;
    this->notes.emplace_back("");
}

void vehicle::print() {
    cout << year << " " << make << " " << model << " from " << year <<
    " has mileage " << miles << " and cost $" << price << endl;
}

bool vehicle::compareCost(const vehicle &a) const {
    if (price > a.price)
        return true;
    return false;
}

void vehicle::add_note(string notes) {
    this->notes.push_back(notes);
}

void vehicle::print_notes() {
    for (auto &note: notes) {
        cout << note << endl;
    }
}

int main() {
    vehicle c1;
    c1.print();
    vehicle c2("Ford", "Focus", 2002, 3000, 150000);
    c2.print();
    vehicle c3("Chevy", "Silverado", 2010);
    c3.print();
    cout << boolalpha << c2.compareCost(c1) << endl;
    cout << boolalpha << c1.compareCost(c2);
    c1.add_note("Has flat tire");
    c1.add_note("Smells bad..");
    c1.print_notes();
    return 0;
}
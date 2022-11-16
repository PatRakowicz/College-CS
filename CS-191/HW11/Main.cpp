//
// Created by Livid on 4/11/2022.
//


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


/**
 * Constructor for sample vehicle
 *  * Set note of vehicle to empty
 * input Null
 * return Null
 */
vehicle::vehicle() {
    make = "Toyota";
    model = "Prius";
    year = 2020;
    price = 25000;
    miles = 1000;
    notes.emplace_back("");
}

/**
 * Constructor for vehicle with 3 inputs
 * * Set note of vehicle to empty
 *
 * @param make | Given string for make of vehicle
 * @param model | Given string for model of vehicle
 * @param year | Given Integer for year of vehicle
 */
vehicle::vehicle(string make, string model, int year) {
    this->make = make;
    this->model = model;
    this->year = year;
    price = 0;
    miles = 0;
    this->notes.emplace_back("");
}

/**
 * Constructor for vehicle with 5 inputs
 *  * Set note of vehicle to empty
 *
 * @param make | Given string for make of vehicle
 * @param model | Given string for model of vehicle
 * @param year | Given Integer for year of vehicle
 * @param price | Given Float for price of vehicle
 * @param miles | Given Integer for Miles on vehicle
 */
vehicle::vehicle(string make, string model, int year, float price, int miles) {
    this->make = make;
    this->model = model;
    this->year = year;
    this->price = price;
    this->miles = miles;
    this->notes.emplace_back("");
}

/**
 * Constructor to display vehicle class
 */
void vehicle::print() {
    cout << year << " " << make << " " << model << " from " << year <<
    " has mileage " << miles << " and cost $" << price << endl;
}

/**
 * Constructor to compare cost of two vehicles, given one from input
 * @param a | Given vehicle to compare with
 * @return | True if initial compared vehicle is more then given from outside
 */
bool vehicle::compareCost(const vehicle &a) const {
    if (price > a.price)
        return true;
    return false;
}

/**
 * Constructor ffor adding notes to given vehicle
 * @param notes  | string input for note on vehicle
 */
void vehicle::add_note(string notes) {
    this->notes.push_back(notes);
}

/**
 * Constructor to print given vehicle notes,
 * displayed on different lines
 */
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
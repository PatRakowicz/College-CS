#include <iostream>
#include <string>

using namespace std;

class house {
private:
public:
    int sq_feet;
    int num_bedroom;
    float num_bathroom;
    string address;

    house();
    house(int sq_feet, int num_bedroom, float num_bathroom, string address);
    void print();
};

house::house() {
    sq_feet = 0;
    num_bedroom = 0;
    num_bathroom = .5;
    address = "1 1st court";
}

house::house(int sq_feet, int num_bedroom, float num_bathroom, string address) {
    this->sq_feet = sq_feet;
    this->num_bedroom = num_bedroom;
    this->num_bathroom = num_bathroom;
    this->address = address;
}

void house::print() {
    cout << address << " Has .." << endl;
    cout << num_bedroom << " Bedrooms " << endl;
    cout << num_bathroom << " Bathrooms " << endl;
    cout << sq_feet << " Square Feet " << endl;
}

void compare_house(house a, house b) {
    if(a.sq_feet > b.sq_feet) {
        cout << a.address << " Is larger" << endl;
    } else {
        cout << b.address << " Is Larger" << endl;
    }
}

int main() {
    house h1;
    h1.print();
    h1.num_bedroom = 3;
    h1.print();
    cout << endl;
    house h2(1500, 2, 1.5, "1 Devner Ave");
    h2.print();
    cout << endl;
    compare_house(h1, h2);
    return 0;
}

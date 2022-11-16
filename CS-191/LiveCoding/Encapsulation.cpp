#include <iostream>
#include <string>

using namespace std;

class classroom {
private:
public:
    int capacity;
    bool computers; // true if computers available, false otherwiase
    bool chalkboards; // true if has chalkboards, false otherwise
    int sq_feet;

    classroom(); // default contrustor
    classroom(int capacity, bool computers, bool chalkboards, int sq_feet);

    void print_info();
}

classroom::classroom() {
    this->capacity = 0;
    this->computers = false;
    this->chalkboards = false;
    this->sq_feet = 0;
}

classroom::classroom(int capacity, bool computers, bool chalkboards, int sq_feet) {
    this->capacity = capacity;
    this->computers = computers;
    this->chalkboards = chalkboards;
    this->sq_feet = sq_feet;
}

void classroom::print_info() {
    cout << capacity << endl;
    cout << computers << endl;
    cout << chalkboards << endl;
    cout << sq_feet << endl;

}

int main() {
    classroom c1(25, false, false, 1000);
    c1.print_info();

    return 0;
}

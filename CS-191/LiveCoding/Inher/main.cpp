#include <iostream>
#include <string>
using namespace std;

#include "Bears.h"

int main() {

    Bear b;
    cout << b.get_type() << " " << b.get_legs() << endl;
    b.set_legs(-3);
    b.set_legs(4);
    b.set_type("Sloth");
    cout << b.get_type() << " " << b.get_legs() << endl;
    return 0;
}
// inheritance HW
#include <iostream>
#include <string>

using namespace std;

#include "UnitSquare.h"

int main() {
    cout << "Testing s with default constructor and changing height to negative\n";
    Square s;
    cout << s.get_height() << " " << s.get_width() << endl;
    s.set_height(-10);
    cout << s.get_height() << " " << s.get_width() << endl;

    cout << "Testing s1 with constructor negative value in constructor\n";
    Square s1(-4);
    cout << s1.get_height() << " " << s1.get_width() << endl;

    cout << "Testing s2 with normal constructor value\n";
    Square s2(5);
    cout << s2.get_height() << " " << s2.get_width() << endl;


    cout << "Testing r with default constructor\n";
    Rectangle r;
    cout << r.get_height() << " " << r.get_width() << endl;

    cout << "Testing r2 with normal constructor, the set_width, and get_area functions\n";
    Rectangle r1(2, 6);
    cout << r1.get_height() << " " << r1.get_width() << endl;
    r1.set_width(5);
    cout << r1.get_height() << " " << r1.get_width() << endl;
    cout << r1.get_area() << endl;

    cout << "Testing r3 to break normal constructor\n";
    Rectangle r3(5, -2);

    cout << "Testing u, trying to break by setting height, test get_area()\n";
    UnitSquare u;
    u.set_height(4);
    cout << u.get_height() << " " << u.get_width() << endl;
    cout << u.get_area() << endl;
    return 0;
}



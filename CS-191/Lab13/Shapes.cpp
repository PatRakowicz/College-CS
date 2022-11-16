//
// Created by Livid on 15/11/2022.
//

#include <iostream>
#include <string>

using namespace std;

#include "Square.h"

int main() {
    Square s;
    cout << s.get_height() << " " << s.get_width() << endl;
    Rectangle r;
    cout << r.get_height() << " " << r.get_width() << endl;
    Rectangle r1(2, 6);
    cout << r1.get_height() << " " << r1.get_width() << endl;
    r1.set_width(5);
    cout << r1.get_height() << " " << r1.get_width() << endl;
    return 0;

}

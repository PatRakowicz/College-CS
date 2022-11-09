//
// Created by mo on 11/9/22.
//

#include <iostream>
#include <string>
using namespace std;

#include "Fruit.h"


int main() {
    Fruit pear;
    pear.set_color("Green");
    cout << pear.get_peel() << " " << pear.get_color() << endl;
    return 0;
}


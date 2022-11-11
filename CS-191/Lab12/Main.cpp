//
// Created by mo on 11/9/22.
//
#include <iostream>
#include <string>
using namespace std;

#include "Cat.h"

int main() {
    Cat c1;
    c1.set_name("Bobby");
    c1.set_weight(12);
    c1.set_age(8);
    c1.print();
    return 0;
}
//
// Created by mo on 11/9/22.
//
#include <iostream>
#include <string>

using namespace std;

#include "Cat.h"

int main() {
    Cat<int> kitty;
    kitty.set_name("Ms. Kittens");
    kitty.set_age(-1);
    kitty.set_weight(-12);
    kitty.set_age(10);
    kitty.set_weight(13);
    kitty.print();

    Cat<float> c("Jerry", 10.16, 15.3);
    c.print();
    c.set_weight(18.5);
    c.print();
    return 0;
}
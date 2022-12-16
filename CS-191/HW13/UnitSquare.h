//
// Created by Livid on 23/11/2022.
//

#include "Square.h"


#ifndef LAB13_UNITSQUARE_H
#define LAB13_UNITSQUARE_H

class UnitSquare : public Square {
public:
    UnitSquare();
    void set_height(int s_height);
    void set_width(int s_width);
};

UnitSquare::UnitSquare() {
    width = 1;
    height = 1;
}

void UnitSquare::set_height(int s_height) {
    cout << "ERROR: can not update height of Unit Square" << endl;
}

void UnitSquare::set_width(int s_width) {
    cout << "ERROR: can not update width of Unit Square" << endl;
}

#endif //LAB13_UNITSQUARE_H

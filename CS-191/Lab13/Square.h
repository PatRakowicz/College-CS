//
// Created by Livid on 15/11/2022.
//
#include "Rectangle.h"

#ifndef LAB13_SQUARE_H
#define LAB13_SQUARE_H

class Square : public Rectangle {
private:
public:
    Square();
    Square(int width);
    void set_height(int s_height);
    void set_width(int s_width);
};

Square::Square() {
    width = 1;
    height = 1;
}

Square::Square(int width) {
    this->width = width;
    this->height = width;
}

void Square::set_height(int s_height) {
    Rectangle::set_height(s_height);
    Rectangle::set_width(s_height);
}

void Square::set_width(int s_width) {
    Rectangle::set_width(s_width);
    Rectangle::set_height(s_width);
}


#endif //LAB13_SQUARE_H

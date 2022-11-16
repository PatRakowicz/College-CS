//
// Created by Livid on 15/11/2022.
//

#ifndef LAB13_RECTANGLE_H
#define LAB13_RECTANGLE_H


class Rectangle {
protected:
    int width;
    int height;
public:
    Rectangle();
    Rectangle(int s_height, int s_width);
    void set_height(int s_height);
    void set_width(int s_width);
    int get_height();
    int get_width();
    int get_area();
};

Rectangle::Rectangle() {
    height = 1;
    width = 2;
}

Rectangle::Rectangle(int height, int width) {
    this->width = width;
    this->height = height;
}

void Rectangle::set_height(int s_height) {
    height = s_height;
}

void Rectangle::set_width(int s_width) {
    width = s_width;
}

int Rectangle::get_height() {
    return height;
}

int Rectangle::get_width() {
    return width;
}

int Rectangle::get_area() {
    return width * height;
}

#endif //LAB13_RECTANGLE_H

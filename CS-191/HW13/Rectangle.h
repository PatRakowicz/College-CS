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

    virtual void set_height(int s_height);

    virtual void set_width(int s_width);

    int get_height();

    int get_width();

    int get_area();
};

Rectangle::Rectangle() {
    height = 1;
    width = 2;
}

Rectangle::Rectangle(int height, int width) {
    if (height <= 0) {
        cout << "ERROR: can not update to negative height" << endl;
        height = 1;
    } else if (width <= 0) {
        cout << "ERROR: can not update to negative width" << endl;
        width = 1;
    } else {
        this->height = height;
        this->width = width;
    }
}

void Rectangle::set_height(int s_height) {
    if (s_height <= 0)
        cout << "ERROR: can not set height of rectangle to negative value" << endl;
    else
        height = s_height;
}

void Rectangle::set_width(int s_width) {
    if (s_width <= 0)
        cout << "ERROR: can not set width of rectangle to negative value" << endl;
    else
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

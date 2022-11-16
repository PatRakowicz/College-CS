//
// Created by mo on 11/9/22.
//

#ifndef OOP_MAIN_H
#define OOP_MAIN_H


class Fruit {
private:
    bool peel; // true if has peel, false otherwise
    string color;
public:
    Fruit();
    void set_peel(bool u_peel);
    void set_color(string u_color);
    bool get_peel();
    string get_color();
};

Fruit::Fruit() {
    peel = false;
    color = "red";
}

void Fruit::set_peel(bool u_peel) {
    peel = u_peel;
}

void Fruit::set_color(string u_color) {
    if (u_color == "chrome")
        cout << "Silly, fruits aren't chrome..\n";
    else
        color = u_color;

}

bool Fruit::get_peel() {
    return peel;
}

string Fruit::get_color() {
    return color;
}


#endif //OOP_MAIN_H

//
// Created by Rako on 11/16/22.
//


#ifndef INHER_ANIMAL_H
#define INHER_ANIMAL_H
class Animal {
protected:
    int legs;
public:
    Animal();
    void set_legs(int legs);
    int get_legs();
};

Animal::Animal() {
    legs = 0;
}

void Animal::set_legs(int legs) {
    if (legs < 0)
        cout << "Error, Enter correct ammount of legs" << endl;
    else
        this->legs = legs;
}

int Animal::get_legs() {
    return legs;
}


#endif //INHER_ANIMAL_H

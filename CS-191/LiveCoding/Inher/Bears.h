//
// Created by Rako on 11/16/22.
//

#ifndef INHER_BEARS_H
#define INHER_BEARS_H
#include "Animal.h"

class Bear : public Animal {
private:
    string type;
public:
    Bear();
    void set_type(string type);
    string get_type();
};

Bear::Bear() {
    type = "Grizzly";
}

void Bear::set_type(string type) {
    this->type = type;
}

string Bear::get_type() {
    return type;
}

#endif //INHER_BEARS_H

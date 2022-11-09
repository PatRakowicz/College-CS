//
// Created by mo on 11/9/22.
//

#ifndef LAB12_MAIN_H
#define LAB12_MAIN_H


class Cat {
private:
    string name;
    int age;
    int weight;
public:
    Cat();
    void set_name(string u_name);
    void set_age(int u_age);
    void set_weight(int u_weight);
};

Cat::Cat() {
    name = "";
    age = 0;
    weight = 0;
}

void Cat::set_name(string u_name) {
    name = u_name;
}

void Cat::set_age(int u_age) {
    if(u_age < 0)
        cout << "Can not go below 0" << endl;
    else
        age = u_age;
}

void Cat::set_weight(int u_weight) {
    if(u_weight < 1)
        cout << "Can not set below 1" << endl;
    else
        weight = u_weight;
}


#endif //LAB12_MAIN_H

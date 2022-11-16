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
    void print();
    string get_name();
    int get_age();
    int get_weight();
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
    if(u_weight < 0)
        cout << "Can not set below 0" << endl;
    else
        weight = u_weight;
}

void Cat::print() {
    cout << "Name : " << name << endl;
    cout << "Age: " << age << endl;
    cout << "Weight: " << weight << endl;
}

string Cat::get_name() {
    return name;
}

int Cat::get_age() {
    return age;
}

int Cat::get_weight() {
    return weight;
}


#endif //LAB12_MAIN_H

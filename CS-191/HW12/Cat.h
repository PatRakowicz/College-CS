//
// Created by mo on 11/9/22.
//

#ifndef LAB12_MAIN_H
#define LAB12_MAIN_H

template<class T>
class Cat {
private:
    string name;
    T age;
    T weight;
public:
    Cat();
    Cat(string u_name, T u_age, T u_weight);
    void set_name(string u_name);
    void set_age(T u_age);
    void set_weight(T u_weight);
    void print();
    string get_name();
    T get_age();
    T get_weight();
};

/** Default Constructor, set all values to 0 or ""
 *
 * @tparam T | Class template for int and float
 */
template<class T>
Cat<T>::Cat() {
    name = "";
    age = 0;
    weight = 0;
}

/** Input constructor for one line
 *
 * @tparam T | Class template for values
 * @param u_name | input value to have user input name
 * @param u_age | input value to be set in main function
 * @param u_weight | input value t get set in main function with float or int
 */
template<class T>
Cat<T>::Cat(string u_name, T u_age, T u_weight) {
    name = u_name;

    if (u_age < 0)
        cout << "Error, need valid age" << endl;
    else
        age = u_age;

    if (u_weight < 0)
        cout << "Error, need valid weight" << endl;
    else
        weight = u_weight;;
}

/** Set function to name
 *
 * @tparam T | class template to follow
 * @param u_name | input string name from user
 */
template<class T>
void Cat<T>::set_name(string u_name) {
    name = u_name;
}

/** Set function for age
 *
 * @tparam T | class template to follow
 * @param u_age | input age from user, check if input is valid
 */
template<class T>
void Cat<T>::set_age(T u_age) {
    if (u_age < 0)
        cout << "Error, need valid age" << endl;
    else
        age = u_age;
}

/** Setter from user to input weight
 *
 * @tparam T | class template to follow
 * @param u_weight | Input from user, check if input is valid
 */
template<class T>
void Cat<T>::set_weight(T u_weight) {
    if (u_weight < 0)
        cout << "Error, need valid weight" << endl;
    else
        weight = u_weight;
}

/** Print constructor
 *
 * @tparam T | class template to follow
 */
template<class T>
void Cat<T>::print() {
    cout << name << " is " << age << " year(s) old and weighs "
         << weight << "lbs" << endl;
}

/** Get Name constructor
 *
 * @tparam T | class template to follow
 * @return | name of the given cat
 */
template<class T>
string Cat<T>::get_name() {
    return name;
}

/** Get Age constructor
 *
 * @tparam T | class template to follow
 * @return | age of the given cat
 */
template<class T>
T Cat<T>::get_age() {
    return age;
}

/** Get weight of given cat
 *
 * @tparam T | class template to follow
 * @return | Weight of given cat, w/ param in main
 */
template<class T>
T Cat<T>::get_weight() {
    return weight;
}


#endif //LAB12_MAIN_H

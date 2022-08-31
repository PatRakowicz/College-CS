//
// Created by Livid on 29/08/2022.
//

/*
1. Can you multiply an int and a float?
    What is the type of the output? An Integer

2. Can you add a float and a double?
    What is the type of the output? A float or double since double can be either/or

3. Can you divide an int by a float?
    What is the type of the output? Possible, but it will output as a float

4. Can you add an int and a bool?
    What is the type of the output? You can, but it won't print the bool out anything

5. Can you divide an int by an int?
    What is the type of the output? Yes, Just an int will be returned

6. Can you add a string and a string?
    What is the type of the output? Yes, but it will just add both together as one string

7. Can you add a string and an int?
    What is the type of the output? No, It will be hit with a compile error,
    but you can convert int into a string and then print but output will be string

8. Can you multiply a string and an int?
    What is the type of the output? No, going to be the same as 7, Unless int a string,
    but you can't multiply string together, no reason to.

9. Can you add a string and a char?
    What is the type of the output? Yes it
*/

#include <iostream>
#include <string>

using namespace std;

int main() {

    int a = 20;
    int alpha = 22;
    float b = 9.7;
    double c = 23.2;
    bool d = false;
    string e = "test";
    string Echo = "Test";
    char f = 'F';

    cout << "1: " << typeid(a * b).name() << a * b << "\n";
    cout << "2: " << typeid(c + b).name() << c + b << "\n";
    cout << "3: " << typeid(a / b).name() << a / b << "\n";
    cout << "4: " << typeid(a + d).name() << a + d << "\n";
    cout << "5: " << typeid(alpha / a).name() << alpha / a << "\n";
    cout << "6: " << typeid(e + Echo).name() << e + Echo << "\n";
    cout << "7: Error" << "\n"; // typeid(alpha + Echo).name() << alpha + Echo ;
    cout << "8: Error" << "\n"; // typeid(e * a).name() << e * a ;
    cout << "9: " << typeid(e + f).name() << e + f << "\n";

    return 0;
}


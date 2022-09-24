//
// Created by Rako on 9/23/22.
//

/*
 * Declare and initialize variables for the following data types: string, int, and
double. The value you initialize them to can be arbitrary. For each of your
variables, do the following:
 *
 * Create a pointer of that type.
 * Point the pointer to your variable.
 * Print out the address of the pointer, the address of the variable, and the
    value of the variable. All three must be printed using only the pointer.
 * */
#import <iostream>
#import <string>

using namespace std;

int main() {
    string msg = "string";
    string *msg_ptr = &msg;
    int x = 10;
    int *int_ptr = &x;
    double y = 22.2;
    double *dbl_ptr = &y;

    cout << &msg_ptr << " " << msg_ptr << " " << *msg_ptr << endl;
    cout << &int_ptr << " " << int_ptr << " " << *int_ptr << endl;
    cout << &dbl_ptr << " " << dbl_ptr << " " << *dbl_ptr << endl;


    string msg2 = "Hello World";
    string *msg2_ptr = &msg2;

    // Original
    // for (int i = 0; i < msg2.length(); i++) {

    // IDE Change
    for (char c : msg2) {
        cout << c << endl;
    }

    return 0;
}

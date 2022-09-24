//
// Created by Pat Rak on 9/21/22.
//

/*
Create an int. Create a pointer to that int. Can you create a pointer to
your int pointer? How? You might have to do some extra research (look
online!).
 Have two stars on the last pointer and define the pointer

Can you add two addresses together? If so, what do you get back? (just
try printing the result)
 Not possible, will just give int error varuable back

Can you add an int and an address? If so, what do you get back? (just
try printing the result)
 Yes, Will give back correct value jsut 8 bits more

Can you multiply an int and an address? If so, what do you get back?
(just try printing the result) Nope, gives back invalid operation to binary

Can you add a double and an address? If so, what do you get back? (just
try printing the result)

Can you dereference a pointer and use the value as a loop condition? (i.e.,
while *x <10)
*/

#include <iostream>
using namespace std;
int main() {
    int x = 4;
    int *x_ptr = &x;
    int **x_ptr_ptr = &x_ptr;
    cout << &x_ptr_ptr << " " << x_ptr_ptr << " " << endl;

//    int f = 4;
//    int g = 8;
//    cout << (&f + &g) << endl;

    int f = 4;
    int g = 8;
    cout << &f << " " << f + &g << endl;

//    int h = 4;
//    int u = 3;
//    cout << h * &g << endl;

//    double h = 4;
//    double u = 1;
//    cout << h + &u << endl;

    int h = 6;
    int *h_ptr = &h;
    int o = 5;

    while(*h_ptr < 10) {
        *h_ptr++;
    }
}
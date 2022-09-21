//
// Created by Pat Rak on 9/21/22.
//

#include <string>

using namespace std;

int main() {
    //01: incrementing pointers
    int x = 1;
    int *x_ptr = &x;
    (*x_ptr)++;
    cout << *x_ptr << " " << x << endl;

    //02: create various pointer types
    int a = 1;
    int *a_ptr
    int b = 3;
    cout << &a_ptr << " " << a_ptr << " " << *a_ptr;
    cout << &b << endl;
    a_ptr -= 2;
    cout << &a_ptr << " " << a_ptr << " " * a_ptr << endl;

    float f = 1.5;
    float *f_ptr = &f;

    //03: Pointers to pointers
    int L_one = 4;
    int *L_one_ptr = &L_one;
    int **L_one_ptr_ptr = &L_one_ptr;
    cout << &L_one_ptr_ptr << " " << L_one_ptr_ptr << " " << endl;

    //04: messing with poitners, multiplication, etc.
    int y = 4;
    int * y_ptr = &;
    cout << y**y_ptr << endl;
}
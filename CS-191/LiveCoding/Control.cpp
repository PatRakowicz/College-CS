//
// control statement
// multiply via addition
// x and y must be > 0
//

#include <iostream>
#include <string>

using namespace std;

int main() {
    int x = 3;
    int y = 5;

    if (x > 0 && y > 0) {
        int solution = 0;
        for (int i=0; i < y; i++) {
            solution = solution + solution;
        }
        cout << x << endl;
    } else {
        cout << "ERROR" << endl;
    }

    return 0;
}
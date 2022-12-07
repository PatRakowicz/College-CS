#include <iostream>
#include <string>

using namespace std;

#include "LinkedList.h"


int main() {
    cout << "~~ Testing AddHead ~~ \n";
    // testing add to empty
    LinkedList AH = LinkedList();
    AH.addHead("One");
    AH.printList();

    cout << endl;
    // testing add to head with list < 1
    LinkedList AH2 = LinkedList();
    AH2.addHead("One");
    AH2.addHead("Two");
    AH2.addHead("Three");
    AH2.printList();
}
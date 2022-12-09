#include <iostream>
#include <string>

using namespace std;

#include "LinkedList.h"


int main() {
    cout << "~~ Testing AddHead ~~" << endl;
    // Testing add to empty
    LinkedList test = LinkedList();
    test.addHead("One");
    test.printList();
    cout << endl;
    // Test Working

    cout << "~~ Testing AddTail ~~" << endl;
    // Testing add to empty
    LinkedList test5 = LinkedList();
    test5.addTail("One");
    test5.printList();
    cout << endl;
    // Test Working

    cout << "~~ Testing AddHead < 1 ~~" << endl;
    // Testing add to head with list < 1
    LinkedList test2 = LinkedList();
    test2.addHead("One");
    test2.addHead("Two");
    test2.addHead("Three");
    test2.printList();
    cout << endl;
    // Test Working

    cout << "~~ Testing AddTail < 1 ~~" << endl;
    // Testing add to head with list < 1
    LinkedList test6 = LinkedList();
    test6.addTail("One");
    test6.addTail("Two");
    test6.addTail("Three");
    test6.printList();
    cout << endl;
    // Test Working

    cout << "~~ Testing Telephone ~~" << endl;
    // Testing if search == value given
    LinkedList test3 = LinkedList();
    test3.addHead("One");
    test3.addHead("Two");
    test3.addHead("Three");
    test3.telephone("hello");
    test3.printList();
    cout << endl;
    // Test Working

    cout << "~~ Testing addMiddle ~~" << endl;
    LinkedList test4 = LinkedList();
    test4.addHead("One");
    test4.addHead("Two");
    test4.addHead("Three");
    test4.printList();
    test4.addMiddles("Two", "Two-.5");
    cout << endl;
    test4.printList();
    cout << endl;
    // Test Working

    cout << "~~ Testing MessUpMsg ~~ " << endl;
    LinkedList test7 = LinkedList();
    test7.addHead("One");
    test7.addHead("Two");
    test7.addHead("Three");
    test7.printList();
    test7.telephone("Hello");
    test7.messUpMessage("Two", "HeLLo");
    cout << endl;
    test7.printList();
    // Test Working
}
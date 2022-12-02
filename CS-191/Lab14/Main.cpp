#include <iostream>
#include <string>

using namespace std;

#include "LinkedList.h"


int main() {
    LinkedList l1 = LinkedList();

    l1.addHead("test");
//    l1.addHead("test2");
//    l1.addHead("test3");
    l1.addTail("test 4");
    l1.printList();
}
#ifndef LAB14_LINKEDLIST_H
#define LAB14_LINKEDLIST_H

struct node {
    string name;
    string message;
    node *next;
};

class LinkedList {
private:
    node *head;
    node *tail;
public:
    LinkedList();

    ~LinkedList();

    node *search(string value);

    void addHead(string value);

    void addTail(string value);

    void addMiddles(string left, string value);

    void telephone(string m);

    void messUpMessage(string value, string brokenMessage);

    void printList();
};

LinkedList::LinkedList() {
    head = nullptr;
    tail = nullptr;
}

// Not sure how to do
LinkedList::~LinkedList() {
    node * temp = head;
    while(temp != nullptr){
        head = head->next;
        delete head;
    }
}

node *LinkedList::search(string value) {
    return nullptr;
}

void LinkedList::addHead(string value) {
    node *n = new node;
    n->message = "";
}

void LinkedList::addTail(string value) {
    node *n = new node;
    n->message = "";
}

void LinkedList::addMiddles(string left, string value) {
    node *n = new node;
    n->message = "";
}

void LinkedList::telephone(string m) {

}

void LinkedList::messUpMessage(string value, string brokenMessage) {

}

void LinkedList::printList() {

}


#endif //LAB14_LINKEDLIST_H
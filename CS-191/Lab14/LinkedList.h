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
    node *temp = head;
    while (temp != nullptr) {
        delete temp;
        temp = temp->next;
    }
}

node *LinkedList::search(string value) {
    node *temp = head;
    int found = 0;
    int idx = 0;

    if (temp != nullptr) {
        while (temp != nullptr) {
            idx++;
            if (temp->name == value) {
                found++;
                break;
            }
            temp = temp->next;
        }
        if (found == 1) {
            cout << value << " is found at index = " << idx << ".\n";
        } else {
            cout << value << " is not found in the list.\n";
        }
    } else {
        cout << "The list is empty.\n";
    }
}

void LinkedList::addHead(string value) {
    if (head == nullptr) {
        node *n = new node;
        n->message = "";
        n->name = value;
        n->next = head;
        head = n;
        tail = n;
    } else {
        node *n = new node;
        n->message = "";
        n->name = value;
        n->next = head;
        head = n;
    }

}

void LinkedList::addTail(string value) {
    if (head == nullptr) {
        node *n = new node;
        n->message = "";
        n->name = value;
        n->next = tail;
        tail = n;
        head = n;
    } else {
        node *n = new node;
        n->message = "";
        n->name = value;
        n->next = nullptr;
        tail->next = n;
        tail = n;
    }
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
    node *temp = head;
    if (temp == nullptr) {
        cout << "NULL" << endl;
    } else {
        while (temp != nullptr) {
            cout << temp->message << " ";
            cout << temp->name << " ";
            temp = temp->next;
        }
    }
}


#endif //LAB14_LINKEDLIST_H
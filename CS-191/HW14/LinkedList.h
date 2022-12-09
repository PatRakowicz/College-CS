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

    void addMiddles(string leftValue, string value);

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
    node *returnNode = nullptr;
    bool found = false;
    while (!found && temp != nullptr) {
        if (temp->name == value) {
            found = true;
            returnNode = temp;
        } else
            temp = temp->next;
    }
    return returnNode;
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

void LinkedList::addMiddles(string leftValue, string value) {
    node *n = new node;
    node *left = search(leftValue);
    n->name = value;
    n->message = "";
    if (left == nullptr) {
        n->next = head;
        head = n;
    } else if (left->next == nullptr) {
        left->next = n;
        tail = n;
    } else {
        n->next = left->next;
        left->next = n;
    }
}

void LinkedList::telephone(string m) {
    node *temp = head;
    if (temp == nullptr) {
        cout << "ERROR: Empty List" << endl;
    } else {
        while (temp != nullptr) {
            temp->message = m;
            temp = temp->next;
        }
    }
}

void LinkedList::messUpMessage(string value, string brokenMessage) {
    node *start = search(value);
    if (start == nullptr) {
        cout << "ERROR: List is empty!" << endl;
    } else {
        while (start != nullptr) {
            start->message = brokenMessage;
            start = start->next;
        }
    }
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
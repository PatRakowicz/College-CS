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

/**
 * Basic constructor for creating a new linked list
 */
LinkedList::LinkedList() {
    head = nullptr;
    tail = nullptr;
}

/**
 * Deletes all items inside the given linked list
 */
LinkedList::~LinkedList() {
    node *temp = head;
    while (temp != nullptr) {
        delete temp;
        temp = temp->next;
    }
}

/**
 * Search for the node with the given name
 * @param value | Name of node we are looking for
 * @return returnNode | returns the node it was looking for
 */
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

/**
 * Create a node at the beginning of the given list
 * @param value | given value to change the name of the new node
 */
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

/**
 * Created a node and adds it to the end of a given linked list
 * @param value | given value to change the name of the new node
 */
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

/**
 * Add a node with given value of each node
 * @param leftValue | Search for given node specified
 * @param value | Input the value of the name of the node
 */
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

/**
 * Telephone, sets all nodes with a given message
 * @param m | Input for type of message that is going to change all nodes in Linked List
 */
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

/**
 * Mess Up Message, given a linked list it will replace the message after given node
 * @param value | Witch node and everything after that node
 * @param brokenMessage | Replace with broken message that replaces after given node
 */
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


/**
 * Print List
 * Given a linked list it will print both messages and name of each element
 */
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
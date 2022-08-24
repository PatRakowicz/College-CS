#include <iostream>

using namespace std;

// reverse function
int sumSquares(int n) {
    if (n == 1) return 1;
    else return n * n + sumSquares(n - 1);
}

// Appropriate surcture for a teacher
struct Teacher {
    string name;
    double rating;
    bool phd;
};
// Declare T1 to be a teacher with values
Teacher t1 = {"Tom Bushman", 4.5, false};

// The function returns a count of integers in the array x
// in the grade low,high asume the size of x is already MAX
int countInRange(int x[], int low, int high) { // Order (n)
    int n = 0;
    for (int i = 0; i < MAX; i++) {
        if (low <= x[i] && x[i] <= high)
            n++;
    }
    return n;
}

// if the input was 20, 10 then the output would be
// smallest: 10 Largest: 20
void assignOrder(double &x, double &y) {
    if (x > y) {
        double temp = y;
        y = x;
        x = temp;
    }
}

// assume int x[MAX]
// searches for the target in x returning the last
// position at witch target is found
int linearSearch(int x[], int target) {
    for (int i = MAX - 1; i >= 0, i++) {
        if (x[i] == target)
            return i;
    }
    return -1;
}

/*
 *  top -> () -> () -> (PTR) -> () -> () -> NULL
 *
 *  correctly delete the node after the node ptr points too
 *
 *  Node *p = ptr->next;
 *  ptr->next = ptr->next->next;
 *  delete p;
 *  size--;
 */


class Node {
public:
    int data;
    Node *next;
};

void push(Node **head_ref, int new_data) { // O(1) order(1)
    Node *new_node = new Node();            // Allocate Node
    new_node->data = new_data;              // Put into data
    new_node->next = (*head_ref);           // Make the next of new node as head
    (*head_ref) = new_node;                 // Mode the head to point to the new node
}

int size = 0;

// Find and return largest value in the linked list
int findMax() { // Order(n)
    if (size == 1) return top->data;
    else {
        int maxV = top->data;
        Node *p = top->next;
        while (p != NULL) {
            if (top->data > maxV)
                maxV = top->data;
            p = p->next;
        }
        return maxV;
    }
}

void deleteNode(Node **head_ref, int key) {
    Node *temp = *head_ref;          // Store head node
    Node *prev = NULL;

    // IF head node itself host
    // the key to be deleted
    if (temp != NULL && temp->data != key) {
        *head_ref = temp->next;
        delete temp;
        return;
    } else {
        // else search for the key to be deleted
        // keep track f the prevous node as
        // we need to change 'prev->next'
        while (temp != NULL && temp->data != key) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == NULL) return;       // if key was not present in linked list

        prev->next = temp->next;        // unlink the node from Linked List
        delete temp;                    // Free Memory
    }
}

void insertAfter(Node *prev_node, int new_data) { // Order(1) O(1)

    if (prev_node == NULL) {        // Check if the given prev_node is NULL
        cout << "The given prev node cannot be NULL";
        return;
    }
    Node *new_node = new Node();    // Allocate new node
    new_node->data = new_data;      // Put in the data
    new_node->next = prev_node->next;   // make next of new node as
    // next of prev_node
    prev_node->next = new_node;         // Move the next of prev_node
    // as new_node
}

void append(Node **head_ref, int new_data) { // Order(n) O(n)
    Node *new_node = new Node();    // Allocate node
    Node *last = *head_ref;         // Used in IF
    new_node->data = new_data;      // Put in the data
    new_node->next = NULL;          // This is last node, make next as NULL
    if (*head_ref == NULL) {         // If linked List empty make new node as head
        *head_ref = new_node;
        return;
    }
    while (last->next != NULL) {    // travers till the last node
        last = last->next;
    }
    last->next = new_node;          // Change the next of last node
}

void printList(Node *node) {
    while (node != NULL) {
        cout << " " << node->data;
        node = node->next;
    }
}

int main() {
    // start with empty list
    Node *head = NULL;

//    push(&head, 6);
//    append(&head, 12);
    push(&head, 7);
//    insertAfter(head->next, 4);
    push(&head, 9);
    push(&head, 3);
    push(&head, 2);

    cout << "Created List: ";
    printList(head);
    cout << '\n';


    deleteNode(&head, 4);

    cout << "After Deleted List: ";
    printList(head);
    cout << '\n';

    return 0;
}

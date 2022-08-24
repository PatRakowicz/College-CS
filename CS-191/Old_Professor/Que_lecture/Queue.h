//
// Created by Pat Rak on 4/22/22.
//

#ifndef QUE_QUEUE_H
#define QUE_QUEUE_H

struct Node {
    int data;
    Node *next;
};

class Queue {
private:
    Node *head, *tail;
    int size;

public:
    Queue();

    void append(int);

    int serve();

    bool isEmpty();
};


#endif //QUE_QUEUE_H

/**
	CS280 linked list header file
	@file linked-list.h
	@author Patrick Rakowicz
	@version 2/16/2023
*/
#ifndef LL_H_
#define LL_H_

#include <iostream>

using namespace std;

// must use this struct
struct city {
    string name;
    string message;
    city *next;
    city *previous;
};

class linkedList {
private:
    city *head;
    city *tail;
public:
    linkedList(); //constructor
    void addCity(string prev, string name); //method for inserting a new node
    void deleteCity(string name); //method for removing a node
    void sendMessage(string message, string cityName); //message function
    void deleteList(); //method to delete all the cities you've created
    void printList(); // method (already implemented) that will print the cities
    void printListBack(); // method for printing the list backwards (you implement)
};

// Constructor
// should just set both head and tail to nullptr
linkedList::linkedList() {
    head = nullptr;
    tail = nullptr;
}

/*
* Method name: addCity
* Purpose: accepts a name and creates a new node, puts it in the list after prev
* @param prev - the node you want to insert after ("" for putting at head)
* @param name - the name of the new city you want to create
* @return - none
* Note: create a new city with message value "", search the
*	list for prev, and put your new node after prev. Note that we have several cases
*	to consider, empty list, inserting at the beginning, inserting at the end,
*	and inserting somewhere else in list
*/
void linkedList::addCity(string prev, string name) {
    city *newCity = new city{name, "", nullptr, nullptr};

    if (head == nullptr) {
        head = newCity;
        tail = newCity;
    } else if (prev == "" || head->name == prev) {
        newCity->next = head;
        head->previous = newCity;
        head = newCity;
    } else {
        city *prevCity = head;
        while (prevCity != nullptr && prevCity->name != prev) {
            prevCity = prevCity->next;
        }
        if (prevCity == nullptr) {
            newCity->previous = tail;
            tail->next = newCity;
            tail = newCity;
        } else {
            newCity->next = prevCity->next;
            if (prevCity->next != nullptr) {
                prevCity->next->previous = newCity;
            }
            prevCity->next = newCity;
            newCity->previous = prevCity;
        }
    }
}


/*
* Method name: deleteNode
* Purpose: accepts a name and removes the city with that name from the list
* @param name - the name of the city of the node you want to delete
* @param name - the name of the new city you want to create
* @return - none
*/
void linkedList::deleteCity(string name) {
    if (head == nullptr) {
        cout << "List is empty" << endl;
        return;
    }

    if (head->name == name) {
        head = head->next;
        if (head != nullptr) {
            head->previous = nullptr;
        } else {
            tail = nullptr;
        }
        return;
    }

    city *currCity = head;
    while (currCity != nullptr && currCity->name != name) { currCity = currCity->next; }

    if (currCity == nullptr) {
        cout << "City not found" << endl;
        return;
    }

    if (currCity->previous != nullptr) { currCity->previous->next = currCity->next; }
    if (currCity->next != nullptr) { currCity->next->previous = currCity->previous; }
    if (currCity == tail) { tail = currCity->previous; }
    delete currCity;
}

/*
* Method name: sendMessage
* Purpose: sends a message to a city and its neighbors
* @param message - the message to send
* @param cityName - the name of the city you want to send the message from
* @return - none
* Note: a hint, search for your city, if it isn't the head or tail, send message to
*		both neighbors, if it's head or tail, handle accordingly.
*/
void linkedList::sendMessage(string message, string cityName) {
    if (head == nullptr) {
        cout << "List is empty" << endl;
        return;
    }

    city *currCity = head;
    while (currCity != nullptr && currCity->name != cityName) {
        currCity = currCity->next;
    }
    if (currCity == nullptr) {
        cout << "City not found" << endl;
        return;
    }

    currCity->message = message;
    cout << "Message sent to " << currCity->name << ": " << message << endl;

    if (currCity->previous != nullptr) {
        currCity->previous->message = message;
        cout << "Message sent to " << currCity->previous->name << ": " << message << endl;
    }

    if (currCity->next != nullptr) {
        currCity->next->message = message;
        cout << "Message sent to " << currCity->next->name << ": " << message << endl;
    }

    if (currCity == head && currCity->next != nullptr) {
        currCity->next->message = message;
        cout << "Message sent to " << currCity->next->name << ": " << message << endl;
    }

    if (currCity == tail && currCity->previous != nullptr) {
        currCity->previous->message = message;
        cout << "Message sent to " << currCity->previous->name << ": " << message << endl;
    }
}

/*
* Method name: deleteList
* Purpose: deletes all the new cities you made for your list
* @return - none
* Note: iterate through you list, deleting each element
*/
void linkedList::deleteList() {
    city *currCity = head;
    while (currCity != nullptr) {
        city *nextCity = currCity->next;
        delete currCity;
        currCity = nextCity;
    }

    head = nullptr;
    tail = nullptr;

    cout << "List deleted" << endl;
}

/*
* Method name: printList
* Purpose: prints each city and message in the list
* @return - none
*/
void linkedList::printList() {
    city *currCity = head;
    while (currCity != nullptr) {
        cout << currCity->name << " ";
        cout << "(" << currCity->message << ") -> ";
        currCity = currCity->next;
    }
    cout << "NULL" << endl;
}

/*
* Method name: printListBack
* Purpose: prints each city and message in the list backwards (starting at the tail)
* @return - none
*/
void linkedList::printListBack() {
    city *currCity = tail;
    while (currCity != nullptr) {
        cout << currCity->name << " ";
        cout << "(" << currCity->message << ") -> ";
        currCity = currCity->previous;
    }
    cout << "NULL" << endl;
}


#endif

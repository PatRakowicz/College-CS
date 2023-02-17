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
    // create a new city with message value ""
    city *newCity = new city;
    newCity->name = name;
    newCity->message = "";
    newCity->next = nullptr;
    newCity->previous = nullptr;

    // if the list is empty, set head and tail to the new city
    if (head == nullptr) {
        head = newCity;
        tail = newCity;
    } else {
        // if prev is empty, add new city to the beginning of the list
        if (prev == "") {
            newCity->next = head;
            head->previous = newCity;
            head = newCity;
        } else {
            // search for prev in the list
            city *current = head;
            while (current != nullptr && current->name != prev) {
                current = current->next;
            }
            if (current == nullptr) {
                // prev not found, add new city to the end of the list
                tail->next = newCity;
                newCity->previous = tail;
                tail = newCity;
            } else {
                // insert new city after prev
                newCity->next = current->next;
                newCity->previous = current;
                if (current->next != nullptr) {
                    current->next->previous = newCity;
                } else {
                    tail = newCity;
                }
                current->next = newCity;
            }
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
    // if the list is empty, do nothing
    if (head == nullptr) {
        return;
    }

    // search for the node to delete
    city *current = head;
    while (current != nullptr && current->name != name) {
        current = current->next;
    }

    if (current == nullptr) {
        // node not found, do nothing
        return;
    }

    if (current == head && current == tail) {
        // deleting the only node in the list
        head = nullptr;
        tail = nullptr;
    } else if (current == head) {
        // deleting the head node
        head = current->next;
        head->previous = nullptr;
    } else if (current == tail) {
        // deleting the tail node
        tail = current->previous;
        tail->next = nullptr;
    } else {
        // deleting a node in the middle of the list
        current->previous->next = current->next;
        current->next->previous = current->previous;
    }

    // free memory allocated for the node
    delete current;
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
    city *current = head;
    bool cityFound = false;
    while (current != nullptr) {
        if (current->name == cityName) {
            cityFound = true;
            break;
        }
        current = current->next;
    }

    if (cityFound) {
        // send message to the current city
        current->message = message;
        cout << "Message sent to " << current->name << ": " << current->message << endl;

        // send message to neighbors if they exist
        if (current != head && current != tail) {
            current->previous->message = message;
            current->next->message = message;
            cout << "Message sent to " << current->previous->name << ": " << current->previous->message << endl;
            cout << "Message sent to " << current->next->name << ": " << current->next->message << endl;
        } else if (current == head && current->next != nullptr) {
            current->next->message = message;
            cout << "Message sent to " << current->next->name << ": " << current->next->message << endl;
        } else if (current == tail && current->previous != nullptr) {
            current->previous->message = message;
            cout << "Message sent to " << current->previous->name << ": " << current->previous->message << endl;
        } else {
            // city is either the only one in the list or an invalid city name was given
            cout << "City not found or has no neighbors to send message to" << endl;
        }
    } else {
        // city not found in list
        cout << "City not found or has no neighbors to send message to" << endl;
    }
}

/*
* Method name: deleteList
* Purpose: deletes all the new cities you made for your list
* @return - none
* Note: iterate through you list, deleting each element
*/
void linkedList::deleteList() {
    // iterate through the list, deleting each node
    city *current = head;
    while (current != nullptr) {
        city *temp = current;
        current = current->next;
        delete temp;
    }

    // set head and tail to nullptr
    head = nullptr;
    tail = nullptr;
}


/*
* Method name: printList
* Purpose: prints each city and message in the list
* @return - none
*/
void linkedList::printList() {
    city *temp;
    temp = head;
    while (temp != nullptr) {
        cout << temp->name << " has message: " << temp->message << endl;
        temp = temp->next;
    }
}

/*
* Method name: printListBack
* Purpose: prints each city and message in the list backwards (starting at the tail)
* @return - none
*/
void linkedList::printListBack() {
    city *current = tail;
    while (current != nullptr) {
        cout << current->name << ":\t" << current->message << endl;
        current = current->previous;
    }
}

#endif

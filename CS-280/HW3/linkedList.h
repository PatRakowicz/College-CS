/**
	CS280 linked list header file
	@file linked-list.h
	@author Sam Micka
	@version 9/11/2020
*/
#ifndef LL_H_
#define LL_H_
#include <iostream>
using namespace std;

// must use this struct
struct city
{
	string name;
	string message;
	city* next;
	city* previous;
};

class linkedList {
private:
	city* head;
	city* tail;
public:
	linkedList(); //constructor
	void addCity(string prev, string name); //method for inserting a new node
	void deleteCity(string name); //method for removing a node
	void sendMessage(string message, string cityName); //message function
	void deleteList(); //method to delete all of the cities you've created
	void printList(); // method (already implemented) that will print the cities
	void printListBack(); // method for printing the list backwards (you implement)
};

// Constructor
// should just set both head and tail to NULL
linkedList::linkedList() {
	// implement here!
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
void linkedList::addCity(string prev, string name)
{
	// implement here!
}


/*
* Method name: deleteNode
* Purpose: accepts a name and removes the city with that name from the list
* @param name - the name of the city of the node you want to delete
* @param name - the name of the new city you want to create
* @return - none
*/
void linkedList::deleteCity(string name)
{
	// implement here!
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
void linkedList::sendMessage(string message, string cityName)
{
	//implement here!
}

/*
* Method name: deleteList
* Purpose: deletes all the new cities you made for your list
* @return - none
* Note: iterate through you list, deleting each element
*/
void linkedList::deleteList()
{
	//implement here!
}

/*
* Method name: printList
* Purpose: prints each city and message in the list
* @return - none
*/
void linkedList::printList()
{
	city* temp;
	temp = head;
	while(temp != NULL)
	{
		cout << temp->name << " has message: " << temp->message << endl;
		temp = temp->next;
	}
}

/*
* Method name: printListBack
* Purpose: prints each city and message in the list backwards (starting at the tail)
* @return - none
*/
void linkedList::printListBack()
{
	// implement here!
}


#endif

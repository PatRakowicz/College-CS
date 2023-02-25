/**
	CS280 BST
	@file bst.h
	@author Sam Micka
	@version 9/23/2020
*/
#ifndef BST_H_
#define BST_H_
#include <iostream>
using namespace std;

// must use this struct
struct movie
{
	string title;
	int rating;
	int year;
	movie* parent;
	movie* leftChild;
	movie* rightChild;
};

class bst {
private:
	movie* root;
	void destroy(movie* node); // helper function for destructor
public:
	bst(); //constructor
	~bst(); //destructor
	movie* search(string title); // returns the node with the matching title
	void addMovie(string name, int rating, int year); //method for inserting a new movie
	void deleteMovie(string title); //method for removing a movie
	movie* findMin(movie* node); //helper function for deleteMovie
	void findMovie(string title); // method for finding and printing out the information about a movie
	void printMoviesRating(int rating); // helper function
	void printMoviesRating(movie* node, int rating); // method to print all movies in order with rating above a certain value
	void printMovies(); // helper function
	void printMovies(movie* node); // method (already implemented) that will print the movies in order
};

// Constructor
bst::bst() {
	//implement!
}

/*
* Method name: destroy
* Purpose: helper method for the destructor
* @param node - the current node
* @return none
* Note: recursively destroy nodes, doing a post-order traversal
*/
void bst::destroy(movie* node)
{
	//implement!
}

// Destructor
// use a post-order traversal to delete movies one at a time by
// calling destory with root
bst::~bst() {
	//implement!
}


/*
* Method name: search
* Purpose: accepts a title searches the tree for the title
* @param title - the title of the movie
* @return - pointer to the movie node with the title
* Note: Use the iterative approach (not recursive) so we don't
* 	have to send another node parameter.
* 	You can call this from various other methods!
*/
movie* bst::search(string title)
{
	//implement!
}

/*
* Method name: addMovie
* Purpose: accepts a title and creates a new movie node, puts it in the BST
* @param title - the title of the movie
* @param rating - the integer rating of the movie
* @param year - the integer year that the movie came out
* @return - none
* Note: Create a new movie node with the specified parameters.
* 	then go through the tree to put it in the lexicographically correct
* 	spot in the tree.
*/
void bst::addMovie(string title, int rating, int year)
{	
	//implement!
}


/*
* Method name: findMin
* Purpose: accepts a node that you want to start your search at and returns the minimum
* 	value node in that subtree
* @param node - the start node
* @return - the node with the smallest title in the subtree starting at node
* Note: this is a helper function for deleteMovie!
*/
movie* bst::findMin(movie* node)
{
	//implement!
}

/*
* Method name: deleteMovie
* Purpose: accepts a title and removes
* @param title - the title of the movie to be removed 
* @return - none
* Note: find the movie with the title matching the input and
* 	remove it from the tree, remember, you may have to move things
* 	around to maintain the BST properties! You must follow the
* 	pseudocode on pages 178, 179, and 180 in the textbook
*/
void bst::deleteMovie(string title)
{
	//implement!
}

/*
* Method name: findMovie
* @param title - the title of the movie
* @return - none
* Note: find the movie and print out the associated information. Hint,
* 		if you implement search first, this method is very easy!
*/
void bst::findMovie(string title)
{
	//implement!
}

// helper function to call printMoviesRating with root
void bst::printMoviesRating(int rating)
{
	//implement!
}


/*
* Method name: printBST
* Purpose: prints each movie's information, in-order traversal!
* @param node - the node to start at
* @param rating - the cut off rating, for example, rating = 3 then you should
					only print movies with a rating of 3 or higher
* @return - none
*/
void bst::printMoviesRating(movie* node, int rating)
{
	//implement!
}


// helper function to call printMovies with root
void bst::printMovies()
{
	printMovies(root);
}

/*
* Method name: printBST
* Purpose: prints each movie's information, in-order traversal!
* @return - none
*/
void bst::printMovies(movie* node)
{
	if(node!=NULL)
	{
		printMovies(node->leftChild);
		cout << "Title: " << node->title << ", Rating: " << node->rating << ", Year: " << node->year << endl;
		printMovies(node->rightChild);
	}
}
#endif

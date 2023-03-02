/**
	CS280 BST
	@file bst.h
	@author Sam Micka
	@version 9/23/2020
*/
#ifndef BST_H_
#define BST_H_

#include <iostream>
#include <vector>

using namespace std;

// must use this struct
struct movie {
    string title;
    int rating;
    int year;
    movie *parent;
    movie *leftChild;
    movie *rightChild;
};

class bst {
private:
    movie *root;

    void destroy(movie *node); // helper function for destructor
public:
    bst(); //constructor
    ~bst(); //destructor
    movie *search(const string& title); // returns the node with the matching title
    void addMovie(string name, int rating, int year); //method for inserting a new movie
    void deleteMovie(string title); //method for removing a movie
    movie *findMin(movie *node); //helper function for deleteMovie
    void findMovie(string title); // method for finding and printing out the information about a movie
    void printMoviesRating(int rating); // helper function
    void
    printMoviesRating(movie *node, int rating); // method to print all movies in order with rating above a certain value
    void printMovies(); // helper function
    void printMovies(movie *node); // method (already implemented) that will print the movies in order

};

// Constructor
bst::bst() {
    root = nullptr;
}

/*
* Method name: destroy
* Purpose: helper method for the destructor
* @param node - the current node
* @return none
* Note: recursively destroy nodes, doing a post-order traversal
*/
void bst::destroy(movie *node) {
    if (node != nullptr) {
        destroy(node->leftChild);
        destroy(node->rightChild);
        delete node;
    }
}

// Destructor
// use a post-order traversal to delete movies one at a time by
// calling destroy with root
bst::~bst() {
    destroy(root);
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
movie *bst::search(const string& title) {
    movie *current = root;

    while (current != root) {
        if (current->title == title) { return current; }
        else if (current->title > title) { current = current->leftChild; }
        else { current = current->rightChild; }
    }
    return nullptr;
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
void bst::addMovie(string title, int rating, int year) {
    movie *newMovie = new movie();
    newMovie->title = title;
    newMovie->rating = rating;
    newMovie->year = year;
    newMovie->parent = nullptr;
    newMovie->leftChild = nullptr;
    newMovie->rightChild = nullptr;

    if (root == nullptr) {
        root = newMovie;
    } else {
        movie *current = root;
        movie *parent;
        while (true) {
            parent = current;
            if (title < current->title) {
                current = current->leftChild;
                if (current == nullptr) {
                    parent->leftChild = newMovie;
                    newMovie->parent = parent;
                    return;
                }
            }else {
                current = current->rightChild;
                if (current == nullptr) {
                    parent->rightChild = newMovie;
                    newMovie->parent = parent;
                    return;
                }
            }
        }
    }
}


/*
* Method name: findMin
* Purpose: accepts a node that you want to start your search at and returns the minimum
* 	value node in that subtree
* @param node - the start node
* @return - the node with the smallest title in the subtree starting at node
* Note: this is a helper function for deleteMovie!
*/
movie *bst::findMin(movie *node) {
    if (node == nullptr) { return nullptr; }
    while (node->leftChild != nullptr) {
        node = node->leftChild;
    }
    return node;
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
void bst::deleteMovie(string title) {
    movie *nodeDel = search(title);
    if (nodeDel == nullptr) {
        return;
    }

    // Case 1: DelNode is leaf node
    if (nodeDel->leftChild == nullptr && nodeDel->rightChild == nullptr) {
        if (nodeDel == root) {
            root = nullptr;
        } else if (nodeDel == nodeDel->parent->leftChild) {
            nodeDel->parent->leftChild = nullptr;
        } else {
            nodeDel->parent->rightChild = nullptr;
        }
        delete nodeDel;
        return;
    }

    // Case 2: DelNode has only 1 child
    if (nodeDel->leftChild == nullptr || nodeDel->rightChild == nullptr) {
        movie *child = (nodeDel->leftChild != nullptr) ?
                nodeDel->leftChild : nodeDel->rightChild;
        if (nodeDel == root) {
            root = child;
            root->parent = nullptr;
        } else if (nodeDel == nodeDel->parent->leftChild) {
            nodeDel->parent->leftChild = child;
            child->parent = nodeDel->parent;
        } else {
            nodeDel->parent->rightChild = child;
            child->parent = nodeDel->parent;
        }
        delete nodeDel;
        return;
    }

    // Case 3: DelNode has two children
    movie *minNode = findMin(nodeDel->rightChild);
    nodeDel->title = minNode->title;
    nodeDel->rating = minNode->rating;
    nodeDel->year = minNode->year;
    deleteMovie(minNode->title);
}

/*
* Method name: findMovie
* @param title - the title of the movie
* @return - none
* Note: find the movie and print out the associated information. Hint,
* 		if you implement search first, this method is very easy!
*/
void bst::findMovie(string title) {
    movie *node = search(title);

    if (node != nullptr) {
        cout << "Title: " << node->title << endl;
        cout << "Rating: " << node->rating << endl;
        cout << "Year: " << node->year << endl;
    } else {
        cout << "Movie w/ " << title << " could not be found \n";
    }
}

// helper function to call printMoviesRating with root
void bst::printMoviesRating(int rating) {
    printMoviesRating(root, rating);
}


/*
* Method name: printBST
* Purpose: prints each movie's information, in-order traversal!
* @param node - the node to start at
* @param rating - the cut off rating, for example, rating = 3 then you should
					only print movies with a rating of 3 or higher
* @return - none
*/
void bst::printMoviesRating(movie *node, int rating) {
    if (node == nullptr) {
        return;
    }
    printMoviesRating(node->leftChild, rating);
    if (node->rating >= rating) {
        cout << "Title: " << node->title
            << ", Rating: " << node->rating
            << ", Year: " << node->year << endl;
    }
    printMoviesRating(node->rightChild, rating);
}


// helper function to call printMovies with root
void bst::printMovies() {
    printMovies(root);
}

/*
* Method name: printBST
* Purpose: prints each movie's information, in-order traversal!
* @return - none
*/
void bst::printMovies(movie *node) {
    if (node != NULL) {
        printMovies(node->leftChild);
        cout << "Title: " << node->title << ", Rating: " << node->rating << ", Year: " << node->year << endl;
        printMovies(node->rightChild);
    }
}

#endif

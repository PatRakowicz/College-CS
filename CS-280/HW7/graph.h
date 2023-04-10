/**
	CS280 graphs
	@file bst.h
	@author Patrick Rakowicz
	@version 10/04/2023
*/
#ifndef GRAPH_H_
#define GRAPH_H_

#include <iostream>

using namespace std;

#include <vector>
#include <queue> // for use with BFS
#include <stack> // for use with DFS
#include <climits> // for INT_MAX

// must use these structs
// they represent the vertices in our graph
struct adjCity;
struct city;
struct adjCity {
    city *v;
    int weight;
};
struct city {
    string key; // stores the name of the city
    vector<adjCity *> adjacent;
    bool visited; // for traversals (DFS/BFS)
    bool solved; // for Dijsktra's
    int distance; // for keeping track of distance in Dijkstra's
    city *parent; // for keeping track of parent in Dijkstra's
};

class graph {
private:
    vector<city *> vertices;
public:
    graph(); //constructor
    ~graph(); //destructor
    void insertCity(string cityName); // inserts a new vertex (city)
    void insertEdge(string firstCity, string secondCity, int weight); // inserts edge with specified weight
    void printGraph(); // prints each vertex and it's adj vertices
    city *search(string cityName); // finds and returns city
    void bft(string startCity); // prints out the vertices in a BF traversal from the starting city
    void dft(string startCity); // prints out the vertices in a DF traversal from the starting city
    city *dijkstras(string start, string end); // Dijkstra's algorithm!
    void printShortestPath(city *endV); // to be called after Dijkstra's
};


// Constructor
graph::graph() {
    cout << "Constructing." << endl;
}

// Destructor
// need to actually call delete on each struct we made with new
// Should loop through, for each city, delete all adjacent cities, then delete the city
graph::~graph() {
    cout << "Destructing." << endl;
    for (auto &vertice: vertices) { delete vertice; }
}

/*
* Method name: insertCity
* Purpose: accepts a city name, adds a new vertex
* @param cityName - the name of the city
* @return - none
* Notes - should only add if there isn't already a vertex with that key,
* if there is a vertex with that key, print out an "error message"
*/
void graph::insertCity(string cityName) {
    cout << "Inserting " << cityName << endl;

    city* newCity = new city;
    newCity->key = cityName;
    newCity->visited = false;
    newCity->solved = false;
    newCity->distance = INT_MAX;
    newCity->parent = nullptr;
    vertices.push_back(newCity);
}

/*
* Method name: insertEdge
* Purpose: adds an edge between two cities
* @param firstCity - the first city in the edge
* @param secondCity - the second city in the edge
* @param weight - the weight of the edge (useful later for searching)
* @return - none
* Notes - should, technically, add two edges. The edge: firstCity -> secondCity
* and the edge: secondCity -> firstCity.
* You can follow most of the pseudocode in the book, but will need to add some additional
* functionality to add both edges.
*/
void graph::insertEdge(string firstCity, string secondCity, int weight) {
    cout << "Inserting edges between " << firstCity << " and " << secondCity << " with weight " << weight << endl;
    // TODO: implement, make sure to add both edges
}

void graph::printGraph() {
    for (int i = 0; i < vertices.size(); i++) {
        cout << vertices[i]->key << "-->";
        for (int j = 0; j < vertices[i]->adjacent.size(); j++) {
            cout << vertices[i]->adjacent[j]->v->key << "(" << vertices[i]->adjacent[j]->weight << ") ";
        }
        cout << endl;
    }
}

/*
* Method name: search
* Purpose: finds a key and returns the associated city pointer
* @param cityName - the key we are searching for
* @return - the pointer to that city, return NULL if the city we want is not in the graph
*/
city *graph::search(string cityName) {
    cout << "Searching for " << cityName << endl;
    // TODO: implement
    return NULL;
}

/*
* Method name: bft (breadth first traversal)
* Purpose: prints out a breadth first traversal from a start vertex
* @param startCity - the city we are starting from
* @return - none
* Notes - just print each city key as you traverse it, must use a queue!
* At the end, make sure to loop back through vertices, setting visited to false for each!
*/
void graph::bft(string startCity) {
    cout << "Running BFT starting at " << startCity << endl;
    // TODO: implement
}

/*
* Method name: dft (depth first traversal)
* Purpose: prints out a depth first traversal from a start vertex
* @param startCity - the city we are starting from
* @return - none
* Notes - just print each city key as you traverse it, must use a stack!
* At the end, make sure to loop back through vertices, setting visited to false for each!
*/
void graph::dft(string startCity) {
    cout << "Running DFT starting at " << startCity << endl;
    // TODO: implement
}

/*
* Method name: printShortestPath
* Purpose: starts at end vertex, walks backwards to the start
* 	vertex, prints the path in the correct order from start to finish
* @param endV - the city that we found the shortest path to
* @return - none
* Notes - use the parent pointers, may need a data structure to store
* 	the path in the right order
*/
void graph::printShortestPath(city *endV) {
    if (endV->parent != nullptr) { printShortestPath(endV->parent;) }
    cout << endV->key << endl;
}

/*
* Method name: dijkstras
* Purpose: performs the book's description of Dijkstra's algorithm
* 	to find the shortest path from start to end
* @param start - the city name we are starting from
* @param end - the city name that we are searching for
* @return - the pointer to the end vertex
* Notes - use the pseudocode from the book. You can feel free to create
* 	another vector to use to keep track of solved vertices
*/
city *graph::dijkstras(string start, string end) {
    //implement here!
    return NULL;
}

#endif

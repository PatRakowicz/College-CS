/**
	CS280 graphs
	@file bst.h
	@author Patrick Rakowicz
	@version 10/04/2023
*/
#ifndef GRAPH_H_
#define GRAPH_H_

#include <iostream>
#include <cassert>

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

    void testFunction();
};

// Test function to test what each item does
void graph::testFunction() {
    cout << "Running tests...\n";

    // Test 1: Add cities and print the graph
    insertCity("New York");
    insertCity("Los Angeles");
    insertCity("Chicago");
    insertCity("Miami");
    printGraph();

    // Test 2: Add edges and print the graph
    insertEdge("New York", "Los Angeles", 100);
    insertEdge("New York", "Chicago", 50);
    insertEdge("Chicago", "Los Angeles", 75);
    insertEdge("Chicago", "Miami", 60);
    printGraph();

    // Test 3: Run breadth-first traversal
    bft("New York");

    // Test 4: Run depth-first traversal
    dft("New York");

    // Test 5: Run Dijkstra's algorithm
    city *result = dijkstras("New York", "Miami");
    if (result != nullptr) {
        cout << "Shortest path found:\n";
        printShortestPath(result);
    } else {
        cout << "No shortest path found.\n";
    }
}

// Constructor
graph::graph() {
    cout << "Constructing." << endl;
}

// Destructor
// need to actually call delete on each struct we made with new
// Should loop through, for each city, delete all adjacent cities, then delete the city
graph::~graph() {
    cout << "Destructing." << endl;
    for (auto &vertex: vertices) {
        for (auto &adjCity: vertex->adjacent) {
            delete adjCity;
        }
        delete vertex;
    }
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

    city *existingCity = search(cityName);
    if (existingCity != nullptr) {
        cout << "City " << cityName << " already exists in the graph. \n";
        return;
    }

    city *newCity = new city;
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

    city *firstVertex = search(firstCity);
    city *secondVertex = search(secondCity);

    if (firstVertex == nullptr || secondVertex == nullptr) {
        cout << "One or both cities are not found. \n";
        cout << "Edge not created \n";
        return;
    }

    auto *firstAdjCity = new adjCity;
    auto *secondAdjCity = new adjCity;

    firstAdjCity->v = secondVertex;
    firstAdjCity->weight = weight;
    secondAdjCity->v = firstVertex;
    secondAdjCity->weight = weight;

    firstVertex->adjacent.push_back(firstAdjCity);
    secondVertex->adjacent.push_back(secondAdjCity);
}

void graph::printGraph() {
    for (auto &vertice: vertices) {
        cout << vertice->key << "-->";
        for (auto &j: vertice->adjacent) {
            cout << j->v->key << "(" << j->weight << ") ";
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
    for (city *vertex: vertices) {
        if (vertex->key == cityName) {
            return vertex;
        }
    }
    return nullptr;
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

    city *vertex = search(startCity);

    if (vertex == nullptr) {
        cout << "City " << startCity << " not found.\n";
        return;
    }

    vertex->visited = true;
    queue < city * > q;
    q.push(vertex);

    while (!q.empty()) {
        city *n = q.front();
        q.pop();

        for (size_t x = 0; x < n->adjacent.size(); x++) {
            if (!n->adjacent[x]->v->visited) {
                n->adjacent[x]->v->visited = true;
                cout << n->adjacent[x]->v->key << endl;
                q.push(n->adjacent[x]->v);
            }
        }
    }

    // Reset visited flag for all cities in the graph
    for (city *v: vertices) {
        v->visited = false;
    }
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

    city *vertex = search(startCity);

    if (vertex == nullptr) {
        cout << "City " << startCity << " not found.\n";
        return;
    }

    vertex->visited = true;
    vertex->distance = 0;
    stack < city * > s;
    s.push(vertex);

    while (!s.empty()) {
        city *ve = s.top();
        s.pop();
        cout << ve->key << endl;

        for (auto & x : ve->adjacent) {
            if (!x->v->visited) {
                x->v->visited = true;
                s.push(x->v);
            }
        }
    }

    // Reset visited flag for all cities in the graph
    for (city *v: vertices) {
        v->visited = false;
    }
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
    if (endV->parent != nullptr) { printShortestPath(endV->parent); }
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
    city *startV = search(start);
    city *endV = search(end);

    if (startV == nullptr || endV == nullptr) {
        cout << "One or both cities not found.\n";
        return nullptr;
    }

    startV->solved = true;
    startV->distance = 0;

    vector<city *> solved;
    solved.push_back(startV);

    while (!endV->solved) {
        int minDistance = INT_MAX;
        city *solvedV = nullptr;

        for (auto s : solved) {
            for (size_t y = 0; y < s->adjacent.size(); y++) {
                if (!s->adjacent[y]->v->solved) {
                    int dist = s->distance + s->adjacent[y]->weight;

                    if (dist < minDistance) {
                        solvedV = s->adjacent[y]->v;
                        minDistance = dist;
                        solvedV->parent = s;
                    }
                }
            }
        }

        if (solvedV == nullptr) {
            cout << "No path found between " << start << " and " << end << ".\n";
            return nullptr;
        }

        solvedV->distance = minDistance;
        solvedV->solved = true;
        solved.push_back(solvedV);
    }

    return endV;
}

#endif

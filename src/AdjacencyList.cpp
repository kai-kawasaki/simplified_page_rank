#include <iostream>
#include "AdjacencyList.h"

using namespace std;

// prints the PageRank of all pages after p powerIterations in ascending
// alphabetical order of webpages and rounding rank to two decimal places
string AdjacencyList::PageRank(int n){
    // optionally, store your output in a string/stringstream and then return it from this function after printing so that it is easier to test with Catch
    string result;

    // do your page rank

    cout << result;
    return result;
}

void AdjacencyList::addNode(string name) {
    // only adds new nodes
    if (this->dict.find(name) == this->dict.end()) {
        // creates a new node object
        Node newNode;
        newNode.name = name;
        newNode.rank = 0.0;
        this->graph.push_back(newNode);
        this->dict[name] = this->graph.size() - 1;
    }
}

void AdjacencyList::addEdge(string from, string to) {
    // adds an edge to graph
    // makes sure all referenced nodes are in the graph
    addNode(from);
    addNode(to);
    int index = this->dict[from];
    this->graph[index].outlinks.push_back(to);
}

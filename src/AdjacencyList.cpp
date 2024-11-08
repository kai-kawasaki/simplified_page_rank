#include <iostream>
#include <cmath>
#include "AdjacencyList.h"

using namespace std;

// prints the PageRank of all pages after p powerIterations in ascending
// alphabetical order of webpages and rounding rank to two decimal places
string AdjacencyList::PageRank(int n){
    // optionally, store your output in a string/stringstream and then return it from this function after printing so that it is easier to test with Catch
    string result;

    // do your page rank
    // initialize all ranks to 1/N
    for (auto &i : this->list) {
        i.rank = 1.0 / this->list.size();
    }
    float newRank = 0.0;
    for (int i = 0; i < n-1; i++) {
        // calc new rank
        vector<Node> tempList = this->list;
        for (auto x : dict) {
            int index = x.second;
            newRank = 0.0;
            for (auto y : list[index].inlinks) {
                int inIndex = dict[y];
                newRank += tempList[inIndex].rank / tempList[inIndex].outDegree;
            }
            this->list[index].rank = newRank;
        }
    }
    result = getRanks();
    cout << result;
    return result;
}

string AdjacencyList::getRanks() {
    string result;
    for (auto i : this->dict) {
        string rank = to_string(round(this->list[i.second].rank*100.0)/100.0);
        result += i.first + " " + rank.substr(0,rank.size()-4) + "\n";
    }
    return result;
}

void AdjacencyList::addNode(string name) {
    // only adds new nodes
    if (this->dict.find(name) == this->dict.end()) {
        // creates a new node object
        Node newNode;
        newNode.name = name;
        newNode.rank = 0.0;
        newNode.inDegree = 0;
        newNode.outDegree = 0;
        this->list.push_back(newNode);
        this->dict[name] = this->list.size() - 1;
    }
}

void AdjacencyList::addEdge(string from, string to) {
    // adds an edge to graph
    // makes sure all referenced nodes are in the graph
    addNode(from);
    addNode(to);
    int fromIndex = this->dict[from];
    int toIndex = this->dict[to];
    this->list[fromIndex].outlinks.push_back(to);
    this->list[fromIndex].outDegree++;
    this->list[toIndex].inlinks.push_back(from);
    this->list[toIndex].inDegree++;
}

void AdjacencyList::printGraph() {
    for (auto i : this->list) {
        cout << i.name << " - Rank: " << i.rank << " - inDegree: " << i.inDegree << " - outDegree: " << i.outDegree << endl;
        cout << "Inlinks: ";
        for (auto x : i.inlinks) {
            cout << x << ", ";
        }
        cout << endl << "Outlinks: ";
        for (auto x : i.outlinks) {
            cout << x << ", ";
        }
        cout << endl;
    }
}

void AdjacencyList::printDict() {
    for (auto i : this->dict) {
        cout << "Key: " << i.first << ", values: " << i.second << endl;
    }
}




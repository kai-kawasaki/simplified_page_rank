#pragma once

#include <string>
#include <vector>
#include <map>

using namespace std;

class AdjacencyList {
    private:
    struct Node {
        string name;
        vector<string> outlinks;
        float rank;
    };
    //Think about what member variables you need to initialize
    vector<Node> graph;
    map<string, int> dict;
    public:
    //Think about what helper functions you will need in the algorithm
    string PageRank(int n);
    void addNode(string name);
    void addEdge(string from, string to);
    void printGraph();
    void printDict();
    void printRank();
    void printOutlinks();
    void printInlinks();
    void printInlinks(string name);
    void printOutlinks(string name);
    void printRank(string name);
    void printRank(int index);
};

// This class and method are optional.

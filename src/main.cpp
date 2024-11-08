#include <iostream>

#include "AdjacencyList.h"

using namespace std;

int main() {
    int no_of_lines, power_iterations;
    string from, to;
    AdjacencyList graph;
    cin >> no_of_lines;
    cin >> power_iterations;
    for (int i = 0; i < no_of_lines; i++) {
        cin >> from;
        cin >> to;
        // Do Something
        graph.addEdge(from, to);
    }
    //Create a graph object
    //graph.printDict();
    graph.PageRank(power_iterations);
    //graph.printGraph();
}

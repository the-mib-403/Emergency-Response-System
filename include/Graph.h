#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <utility>

class Graph
{
private:
    int numberOfNodes;
    std::vector<std::vector<std::pair<int, int>>> adjacencyList;

public:
    // Constructors
    Graph();

    Graph(int numberOfNodes);

    // Graph Operations
    void addEdge(int source, int destination, int distance);

    // Getters
    int getNumberOfNodes() const;
    const std::vector<std::vector<std::pair<int, int>>>& getAdjacencyList() const;

    // Display
    void displayGraph() const;
};

#endif
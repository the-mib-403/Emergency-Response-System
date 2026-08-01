#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <utility>
#include <limits>

class Graph
{
private:
    int numberOfNodes;
    std::vector<std::vector<std::pair<int, int>>> adjacencyList;

public:
    std::vector<int> dijkstra(int source) const;
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
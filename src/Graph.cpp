#include "../include/Graph.h"
#include <iostream>

// Default Constructor
Graph::Graph()
    : numberOfNodes(0)
{
}

// Parameterized Constructor
Graph::Graph(int numberOfNodes)
    : numberOfNodes(numberOfNodes),
      adjacencyList(numberOfNodes)
{
}

// Add Edge (Undirected Graph)
void Graph::addEdge(int source, int destination, int distance)
{
    adjacencyList[source].push_back({destination, distance});
    adjacencyList[destination].push_back({source, distance});
}

// Getters
int Graph::getNumberOfNodes() const
{
    return numberOfNodes;
}

const std::vector<std::vector<std::pair<int, int>>>& Graph::getAdjacencyList() const
{
    return adjacencyList;
}

// Display Graph
void Graph::displayGraph() const
{
    std::cout << "\n----- City Graph -----\n";

    for (int i = 0; i < numberOfNodes; i++)
    {
        std::cout << "Node " << i << " -> ";

        for (const auto& edge : adjacencyList[i])
        {
            std::cout << "("
                      << edge.first
                      << ", "
                      << edge.second
                      << ") ";
        }

        std::cout << '\n';
    }
}
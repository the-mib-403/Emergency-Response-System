#include "../include/Graph.h"
#include <iostream>
#include <queue>
#include <functional>
Graph::Graph()
    : numberOfNodes(0)
{
}

Graph::Graph(int numberOfNodes)
    : numberOfNodes(numberOfNodes),
      adjacencyList(numberOfNodes)
{
}

void Graph::addEdge(int source, int destination, int distance)
{
    adjacencyList[source].push_back({destination, distance});
    adjacencyList[destination].push_back({source, distance});
}

int Graph::getNumberOfNodes() const
{
    return numberOfNodes;
}

const std::vector<std::vector<std::pair<int, int>>> &Graph::getAdjacencyList() const
{
    return adjacencyList;
}

void Graph::displayGraph() const
{
    std::cout << "\n----- City Graph -----\n";

    for (int i = 0; i < numberOfNodes; i++)
    {
        std::cout << "Node " << i << " -> ";

        for (const auto &edge : adjacencyList[i])
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

std::vector<int> Graph::dijkstra(int source) const
{
    const int INF = std::numeric_limits<int>::max();

    std::vector<int> distance(numberOfNodes, INF);

    std::priority_queue<
        std::pair<int, int>,
        std::vector<std::pair<int, int>>,
        std::greater<std::pair<int, int>>>
        pq;

    distance[source] = 0;

    pq.push({0, source});

    while (!pq.empty())
    {
        auto [currentDistance, currentNode] = pq.top();

        pq.pop();

        if (currentDistance > distance[currentNode])
        {
            continue;
        }

        for (const auto &edge : adjacencyList[currentNode])
        {
            int neighbor = edge.first;
            int weight = edge.second;

            if (distance[currentNode] + weight < distance[neighbor])
            {
                distance[neighbor] = distance[currentNode] + weight;

                pq.push({distance[neighbor], neighbor});
            }
        }
    }

    return distance;
}
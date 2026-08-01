#include <iostream>
#include <vector>

#include "../include/Graph.h"

int main()
{
    Graph city(5);

    city.addEdge(0, 1, 5);
    city.addEdge(0, 2, 8);
    city.addEdge(1, 3, 4);
    city.addEdge(2, 4, 7);
    city.addEdge(3, 4, 3);

    std::vector<int> distance = city.dijkstra(0);

    std::cout << "\nShortest Distance from Node 0\n\n";

    for (int i = 0; i < distance.size(); i++)
    {
        std::cout << "Node " << i << " : " << distance[i] << '\n';
    }

    return 0;
}
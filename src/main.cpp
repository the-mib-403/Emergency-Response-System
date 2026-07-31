#include <iostream>

#include "../include/Graph.h"

int main()
{
    Graph city(5);

    city.addEdge(0, 1, 5);
    city.addEdge(0, 2, 8);
    city.addEdge(1, 3, 4);
    city.addEdge(2, 4, 7);
    city.addEdge(3, 4, 3);

    city.displayGraph();

    return 0;
}
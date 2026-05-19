#include <stdio.h>

#include "./../../lib/graph/graph.h"

int main()
{
    // TODO: Implement

    Graph* g = graph_create(5);

    graph_add_edge(g, 0, 1, 5);
    graph_add_edge(g, 1, 2, 10);

    float d = graph_dijkstra(g, 0, 2);
    printf("Distance 0 -> 2 = %.2f\n", d);

    graph_destroy(g);

    return 0;
}

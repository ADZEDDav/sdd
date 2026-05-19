#include <stdlib.h>

#include <float.h>

#include "graph.h"
#include "./../list/list.h"

// TODO: Implement

Graph *graph_create(int size) 
{
    Graph *g = malloc(sizeof(Graph));
    g->size = size; 

    g->adj = malloc(size * sizeof(float *));
    for (int i = 0; i < size; i++) 
    {
        g->adj[i] = malloc(size * sizeof(float));
        for (int j = 0; j < size; j++)
        {
            if (i == j)
                g->adj[i][j] = 0.0f;
            else 
                 g->adj[i][j] = FLT_MAX;
        }
    }
    return g;
}

void graph_destroy(Graph *g)
{
    if (!g) return; 
    for (int i = 0; i < g->size; i++)
         free(g->adj[i]);
    

    free(g->adj);
    free(g);
}

void graph_add_edge(Graph *g, int node1, int node2, float weight)
{
    if (!g) return;
    if (node1 < 0 || node2 < 0 || node1 >= g->size || node2 >= g->size)
        return;

    g->adj[node1][node2] = weight;
    g->adj[node2][node1] = weight;  // graphe non orienté

}

float graph_dijkstra(Graph *g, int start, int end)
{
    if (!g) return -1;
    if (start < 0 || end < 0 || start >= g->size || end >= g->size) 
         return -1;
    
    int n = g->size; 
    float dist[n];
    int visited[n];

    for (int i = 0; i < n; i++)
    {
        dist[i] = FLT_MAX;
        visited[i] = 0;
    }

    dist[start] = 0;

    for (int k = 0; k < n ; k++)
    {
        int u = -1;
        float best = FLT_MAX; 

        // Trouver le noeud non visite  le plus proche 
        for (int i = 0; i < n; i++ )
        {
            if (!visited[i] && dist[i] < best)
            {
                best = dist[i];
                u = i;
            }
        }
        
        if (u == -1)
            break;

        visited[u] = 1;

        // relaxation 
        for (int v = 0; v < n; v++)
        {
            if (g->adj[u][v] < FLT_MAX)
            {
                float alt = dist[u] + g->adj[u][v];
                if (alt < dist[v])
                     dist[v] = alt;
            }
        }
    }

    return (dist[end] == FLT_MAX) ? -1  : dist[end]; 
}
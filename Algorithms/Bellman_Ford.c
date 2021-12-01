#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define V 9

// returns vertex with min dist wt not those who are not yet incl in spt
int minDist(int dist[], bool sptset[]){
    int min_index;
    int min = INT_MAX;
    for (int i = 0; i < V; i++)
    {
        if (dist[i] <= min && sptset[i] == false)
        {
            min = dist[i];
            min_index = i;
        }        
    }
    return min_index;
}

void printsol(int dist[V]){
    printf("Vertex    Dist from source\n");
    for (int i = 0; i < V; i++)
    {
        printf("%d         %d \n", i,dist[i]);
    }
}

void bellmanford(int graph[V][V], int src){
    int dist[V];
    bool sptset[V];

    //initially all dist are infinite & none are finalised => false
    for (int i = 0; i < V - 1; i++)
    {
        dist[i] = INT_MAX;
        sptset[i] = false;
    }
    // dist of source from source itself is 0
    dist[src] = 0;

    //for V-1 times (same as dijkstra)
    for (int i = 0; i < V-1; i++)
    {
        // taking min vertex which is not finalised yet from dist[]
        int u = minDist(dist,sptset);
        sptset[u] = true;

        for (int v = 0; v < V; v++)
        {
            // if not in sptset & is adjecent to u (edge from v to u exist) & dist[u] != infinite
            // & (dist from source to u) + (dist from u to v) < dist to v directly
            if (!sptset[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
    
    // take one more iteration to check negative edge
    for (int v = 0; v < V-1; v++)
    {
        int u = minDist(dist,sptset);
        sptset[u] = true;
        if (dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v] && !sptset[u] && graph[u][v])
        {
            printf("Graph contains a negative weight cycle");
            return;
        }
    }
    printsol(dist);
}

int main()
{
    // example graph
    int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                        { 0, 0, 4, -14, 10, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };
 
    bellmanford(graph, 0);
    
    return 0;
}
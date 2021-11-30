#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

// no of vertices
#define V 9

// returns the index of vertex with min dist value & not yet included in shortest path tree
int minDistVertex(int dist[], bool sptset[]){

    int min = INT_MAX ;
    int min_index;
    for (int v = 0; v < V; v++)
    {
        if (dist[v]<=min && sptset[v] == false)
        {
            min = dist[v];
            min_index = v;
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

void dijkstra(int graph[V][V], int src){
    // output array - to carry finalised dist
    int dist[V];
    //to store if val is finalised or not (shortest path tree)
    bool sptset[V];

    //initialising dist to infinite, and sptset to false (none finalised yet)
    for (int i = 0; i < V; i++)
    {
        dist[i] = INT_MAX ;
        sptset[i] = false ;
    }

    // Distance of source vertex from itself is always 0
	dist[src] = 0;

    for (int count = 0; count < V; count++)
    {
        // get the min unfinalised element that is not in shortest path tree
        int u = minDistVertex(dist, sptset);

        // included now
        sptset[u] = true ;

        for (int v = 0; v < V; v++)
        {
            // if not in sptset & is adjecent to u (edge from v to u exist) & dist[u] != infinite
            // & (dist from source to u) + (dist from u to v) < dist to v directly
            if (!sptset[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v] ;    // then set dist[v] = that
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
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };
 
    dijkstra(graph, 0);
    
    return 0;
}
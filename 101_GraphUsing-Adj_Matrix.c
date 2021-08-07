// Representation of graph data str using Adjacency Matrix
#include <stdio.h>

// function for creating graph
void adjMatrix(){
    
    int v,e;
    printf("Enter the no of Nodes(vertex) and Edges: \n");
    scanf("%d %d", &v, &e);

    // Creating respective Adjacancy marix
    // & initializing all elements with 0
    int adj[v+1][v+1];  // v+1 bcz, we will use array from 1 to v
                        // and ignore index 0s, to reduce chance of error
    for (int i = 1; i < v+1; i++)
    {
        for (int j = 1; j < v+1; j++)
        {
            adj[i][j] = 0;
        }
    }
    
    // joining nodes (using edges)
    int x,y;
    printf("Enter the indices of the nodes to join\n");
    for (int i = 0; i < e; i++)
    {
        scanf("%d %d", &x, &y);
        adj[x][y] = 1;
        adj[y][x] = 1;   // both =1 , as graph is undirectional
                        // 1-----2 means, A12 = 1, and A21 = 1
    }
    
    // printing the adj matrix
    printf("The Adjecency Matrix is:\n");
    for (int i = 1; i < v+1; i++)
    {
        for (int j = 1; j < v+1; j++)
        {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }
    
}

int main()
{
    adjMatrix();
    return 0;
}
#include <stdio.h>
#include <stdbool.h>

#define V 6 // Number of vertices

// Function to perform DFS and find all nodes in a cluster
void findCluster(int graph[V][V], int node, bool visited[V]) {
    visited[node] = true;
    printf("%d ", node);

    for (int i = 0; i < V; i++) {
        // If there is an edge and the neighbor hasn't been visited
        if (graph[node][i] == 1 && !visited[i]) {
            findCluster(graph, i, visited);
        }
    }
}

int main() {
    // 1. Adjacency Matrix representation of the graph
    // 1 means an edge exists, 0 means no edge
    int graph[V][V] = {
        {0, 1, 0, 0, 0, 0}, // Node 0 connected to 1
        {1, 0, 0, 0, 0, 0}, // Node 1 connected to 0 (Cluster 1)
        {0, 0, 0, 1, 1, 0}, // Node 2 connected to 3, 4
        {0, 0, 1, 0, 1, 0}, // Node 3 connected to 2, 4
        {0, 0, 1, 1, 0, 0}, // Node 4 connected to 2, 3 (Cluster 2)
        {0, 0, 0, 0, 0, 0}  // Node 5 connected to nothing (Cluster 3)
    };

    bool visited[V] = {false};
    int clusterCount = 0;

    printf("Extracting Clusters (Connected Components):\n");

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            clusterCount++;
            printf("Cluster %d: ", clusterCount);
            findCluster(graph, i, visited);
            printf("\n");
        }
    }

    printf("\nTotal number of clusters found: %d\n", clusterCount);

    return 0;
}
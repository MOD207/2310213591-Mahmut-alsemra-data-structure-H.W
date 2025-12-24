#include <stdio.h>
#include <stdbool.h>

#define V 5

void DFS(int graph[V][V], int current, bool visited[V]) {
    visited[current] = true;
    printf("%d ", current);

    for (int i = 0; i < V; i++) {
        if (graph[current][i] == 1 && !visited[i]) {
            DFS(graph, i, visited);
        }
    }
}
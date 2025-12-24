#include <stdio.h>
#include <stdbool.h>

#define V 5

void BFS(int graph[V][V], int startNode) {
    bool visited[V] = {false};
    int queue[V];
    int front = 0, rear = 0;

    visited[startNode] = true;
    queue[rear++] = startNode;

    printf("BFS Traversal: ");

    while (front < rear) {
        int current = queue[front++];
        printf("%d ", current);

        for (int i = 0; i < V; i++) {
            if (graph[current][i] == 1 && !visited[i]) {
                visited[i] = true;
                queue[rear++] = i;
            }
        }
    }
    printf("\n");
}
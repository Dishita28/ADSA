#include <stdio.h>
#include <stdbool.h>

#define V 5
int path[V];

// Function to check if vertex v can be added to the Hamiltonian path
bool isSafe(int v, int graph[V][V], int path[], int pos) {
    // Check if current vertex is adjacent to previous vertex
    if (graph[path[pos - 1]][v] == 0)
        return false;

    // Check if vertex is already included in the path
    for (int i = 0; i < pos; i++)
        if (path[i] == v)
            return false;

    return true;
}

// Recursive function to find Hamiltonian cycle
bool hamCycleUtil(int graph[V][V], int path[], int pos) {
    // Base case: all vertices are included
    if (pos == V) {
        // Check if last vertex connects to the first
        if (graph[path[pos - 1]][path[0]] == 1)
            return true;
        else
            return false;
    }

    // Try different vertices as the next candidate
    for (int v = 1; v < V; v++) {
        if (isSafe(v, graph, path, pos)) {
            path[pos] = v;

            if (hamCycleUtil(graph, path, pos + 1))
                return true;

            path[pos] = -1; // backtrack
        }
    }
    return false;
}

// Function to solve Hamiltonian Cycle problem
bool hamCycle(int graph[V][V]) {
    for (int i = 0; i < V; i++)
        path[i] = -1;

    path[0] = 0; // start at vertex 0

    if (!hamCycleUtil(graph, path, 1)) {
        printf("No Hamiltonian Cycle exists\n");
        return false;
    }

    printf("Hamiltonian Cycle found:\n");
    for (int i = 0; i < V; i++)
        printf("%d ", path[i]);
    printf("%d\n", path[0]); // complete the cycle
    return true;
}

// Main function
int main() {
    // Example graph (Adjacency Matrix)
    int graph[V][V] = {
        {0, 1, 0, 1, 0},
        {1, 0, 1, 1, 1},
        {0, 1, 0, 0, 1},
        {1, 1, 0, 0, 1},
        {0, 1, 1, 1, 0},
    };

    hamCycle(graph);
    return 0;
}

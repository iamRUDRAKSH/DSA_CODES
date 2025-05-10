#include <iostream>
#include <vector>
using namespace std;

#define N 5  // Maze size

// DFS function (recursive implementation)
void dfs(int start, vector<bool>& visited, int graph[N][N]) {
    // Mark the current node as visited
    visited[start] = true;
    cout << "Visited node: " << start << endl;

    // Explore all adjacent nodes
    for (int i = 0; i < N; ++i) {
        if (graph[start][i] == 1 && !visited[i]) {  // Check if there's an edge and if the node is not visited
            dfs(i, visited, graph);  // Recursively visit the node
        }
    }
}

// Helper function to call DFS
void performDFS(int start, int graph[N][N]) {
    vector<bool> visited(N, false);  // Track visited nodes
    cout << "DFS Traversal Starting from node " << start << ":\n";
    dfs(start, visited, graph);  // Call DFS from the start node
}

int main() {
    // Graph adjacency matrix defined inside main
    int graph[N][N] = {
        {0, 1, 0, 0, 0},
        {1, 0, 1, 1, 0},
        {0, 1, 0, 1, 1},
        {0, 1, 1, 0, 1},
        {0, 0, 1, 1, 0}
    };

    int start = 0;  // Starting node
    performDFS(start, graph);  // Perform DFS starting from node 0
    return 0;
}

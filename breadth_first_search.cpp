#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define N 5  // Maze size

// BFS function
void bfs(int graph[N][N], int start) {
    queue<int> q;
    bool visited[N] = {false};

    q.push(start);
    visited[start] = true;

    cout << "BFS Traversal Starting from node " << start << ":\n";
    
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << "Visited node: " << node << endl;

        // Explore all adjacent nodes
        for (int i = 0; i < N; ++i) {
            if (graph[node][i] == 1 && !visited[i]) {
                visited[i] = true;
                q.push(i);
            }
        }
    }
}

// Helper function to call BFS
void performBFS(int start, int graph[N][N]) {
    bfs(graph, start);  // Perform BFS starting from the start node
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
    performBFS(start, graph);  // Perform BFS starting from node 0
    return 0;
}

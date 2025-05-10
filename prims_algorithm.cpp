#include <iostream>
#include <vector>
#include <climits>
#include <queue>
using namespace std;

#define V 5  // Number of vertices

// Prim’s Algorithm using priority_queue
void prim(int graph[V][V]) {
    vector<int> parent(V, -1);  // Array to store the MST
    vector<int> key(V, INT_MAX);  // Key values to pick the minimum weight edge
    vector<bool> mstSet(V, false);  // To check if the vertex is included in the MST

    key[0] = 0;  // Start from vertex 0
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0});  // {weight, vertex}

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        mstSet[u] = true;  // Add vertex u to MST

        // Explore the adjacent vertices of u
        for (int v = 0; v < V; v++) {
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
                pq.push({key[v], v});
                parent[v] = u;
            }
        }
    }

    // Print the MST
    cout << "Edge \tWeight\n";
    for (int i = 1; i < V; i++) {
        cout << parent[i] << " - " << i << " \t" << graph[i][parent[i]] << endl;
    }
}

int main() {
    // Graph representation using adjacency matrix
    int graph[V][V] = { {0, 2, 0, 6, 0},
                        {2, 0, 3, 8, 5},
                        {0, 3, 0, 0, 7},
                        {6, 8, 0, 0, 9},
                        {0, 5, 7, 9, 0} };
    
    prim(graph);
    
    return 0;
}
#include <iostream>
#include <vector>
#include <climits>
#include <queue>
using namespace std;

#define V 9  // Number of vertices

// Dijkstra’s Algorithm using priority_queue
void dijkstra(int graph[V][V], int src) {
    vector<int> dist(V, INT_MAX);  // Stores the shortest distance from src to all vertices
    dist[src] = 0;

    // Priority queue to select the vertex with the minimum distance
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src});  // {distance, vertex}

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        // Explore all adjacent vertices of u
        for (int v = 0; v < V; v++) {
            if (graph[u][v] != 0 && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                pq.push({dist[v], v});
            }
        }
    }

    // Print the shortest distance from src to all vertices
    cout << "Vertex\tDistance from Source\n";
    for (int i = 0; i < V; i++) {
        cout << i << "\t" << dist[i] << endl;
    }
}

int main() {
    // Graph representation using adjacency matrix
    int graph[V][V] = { {0, 4, 0, 0, 0, 0, 0, 8, 0},
                        {4, 0, 8, 0, 0, 0, 0, 0, 0},
                        {0, 8, 0, 7, 0, 4, 0, 0, 0},
                        {0, 0, 7, 0, 9, 14, 0, 0, 0},
                        {0, 0, 0, 9, 0, 10, 0, 0, 0},
                        {0, 0, 4, 14, 10, 0, 2, 0, 0},
                        {0, 0, 0, 0, 0, 2, 0, 1, 6},
                        {8, 0, 0, 0, 0, 0, 1, 0, 7},
                        {0, 0, 0, 0, 0, 0, 6, 7, 0} };
    
    int src = 0;  // Source vertex
    dijkstra(graph, src);
    
    return 0;
}

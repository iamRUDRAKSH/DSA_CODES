#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Edge structure to represent an edge in the graph
struct Edge {
    int u, v, weight;
    bool operator<(Edge const& other) {
        return weight < other.weight;
    }
};

// Disjoint Set Union Find Structure
class DisjointSet {
    vector<int> parent, rank;
public:
    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) parent[i] = i;
    }
    
    int find(int u) {
        if (parent[u] != u)
            parent[u] = find(parent[u]);
        return parent[u];
    }
    
    void unionSets(int u, int v) {
        int rootU = find(u);
        int rootV = find(v);
        
        // Union by rank
        if (rootU != rootV) {
            if (rank[rootU] > rank[rootV]) {
                parent[rootV] = rootU;
            } else if (rank[rootU] < rank[rootV]) {
                parent[rootU] = rootV;
            } else {
                parent[rootV] = rootU;
                rank[rootU]++;
            }
        }
    }
};

// Kruskal's Algorithm to find the Minimum Spanning Tree
void kruskal(int V, vector<Edge>& edges) {
    DisjointSet ds(V);
    sort(edges.begin(), edges.end());  // Sort edges by weight

    int mstWeight = 0;
    vector<Edge> mst;

    for (auto& edge : edges) {
        int u = edge.u;
        int v = edge.v;
        
        // If u and v are not in the same set, include this edge in the MST
        if (ds.find(u) != ds.find(v)) {
            ds.unionSets(u, v);
            mst.push_back(edge);
            mstWeight += edge.weight;
        }
    }

    // Display the edges of the MST
    cout << "Edges in MST:\n";
    for (auto& edge : mst) {
        cout << edge.u << " -- " << edge.v << " == " << edge.weight << endl;
    }
    cout << "Weight of MST: " << mstWeight << endl;
}

int main() {
    int V = 4;
    vector<Edge> edges = { {0, 1, 10}, {0, 2, 6}, {0, 3, 5}, {1, 3, 15}, {2, 3, 4} };
    
    kruskal(V, edges);
    
    return 0;
}
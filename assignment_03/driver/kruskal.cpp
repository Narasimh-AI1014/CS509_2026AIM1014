#include "../src/kruskal.h"
#include <vector>
#include <algorithm>

using namespace std;

class DisjointSet {
private:
    vector<int> parent;
    vector<int> size;
public:
    DisjointSet(int n) {
        parent.resize(n);
        size.resize(n, 1); // Crucial: Base size must be 1, not 0
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    
    int find(int u) {
        if (parent[u] == u) return u;
        return parent[u] = find(parent[u]); // Fixed: assign to parent[u], not local u
    }
    
    bool unionset(int u, int v) {
        int root_u = find(u);
        int root_v = find(v);
        if (root_u == root_v) return false;
        
        // Union by size ranking properties
        if (size[root_u] < size[root_v]) {
            parent[root_u] = root_v;
            size[root_v] += size[root_u];
        } else {
            parent[root_v] = root_u;
            size[root_u] += size[root_v];
        }
        return true;
    }
};

void kruskal(int v, const vector<int> &row_pointer, const vector<int> &colIndex, const vector<int> &weight, vector<mstedge> &mst, int &totalweight) {
    vector<mstedge> edges;
    for (int i = 0; i < v; i++) {
        for (int j = row_pointer[i]; j < row_pointer[i + 1]; j++) {
            int u = i;
            int dest = colIndex[j];
            int w = weight[j];
            if (u < dest) { // Avoids adding symmetric duplicates in undirected inputs
                edges.push_back({u, dest, w});
            }
        }
    }
    
    sort(edges.begin(), edges.end(), [](const mstedge &a, const mstedge &b) {
        return a.weight < b.weight;
    });
    
    DisjointSet dsu(v);
    totalweight = 0;
    mst.clear();
    
    for (const mstedge& edge : edges) {
        if (dsu.unionset(edge.u, edge.v)) {
            mst.push_back(edge);
            totalweight += edge.weight;
        }
        if (mst.size() == (size_t)(v - 1)) {
            break;
        }
    }
}

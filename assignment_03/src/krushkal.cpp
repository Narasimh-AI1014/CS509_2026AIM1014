#include <iostream>
#include <vector>
#include "../driver/csrGraph.h"
using namespace std;

// Structure to store neighbor details in the adjacency list

void prims(vector<int>& row_ptr,vector<int>& column,vector<int>& weight,int v,int source);
// Function to convert an Adjacency List representation into Compressed Sparse Row (CSR) format
void csrGraph(const vector<vector<Neighbor>>& adjList, vector<int>& vertex, vector<int>& child, vector<int>& weight, int v) {
    vector<int> degree(v, 0);
    for (int i = 0; i < v; i++) {
        degree[i] = adjList[i].size();
    }
    
    // Compute the row offsets (row_ptr)
    vertex[0] = 0;
    for (int i = 0; i < v; i++) {
        vertex[i + 1] = vertex[i] + degree[i];
    }

    // Populate the column indices and weights arrays
    for (int i = 0; i < v; i++) {
        int currentChildIndex = vertex[i]; 
        for (const auto& edge : adjList[i]) {
            child[currentChildIndex] = edge.to;       // Destination vertex
            weight[currentChildIndex] = edge.weight;  // Edge weight
            currentChildIndex++;
        }
    }
}

int main() {
    int v;
    cout << "Enter the no.of vertices : ";
    cin >> v;

    int e;
    cout << "Enter the no.of edges  : ";
    cin >> e;

    // 1. Read input and populate the Adjacency List representation
    vector<vector<Neighbor>> adj(v);
    cout << "Enter the graph details (Vertex ID, Degree, followed by [Neighbor Weight] pairs):\n";
    for (int i = 0; i < v; i++) {
        int u, degree;
        cin >> u >> degree;

        for (int j = 0; j < degree; j++) {
            int target_v, w;
            cin >> target_v >> w;
            adj[u].push_back({target_v, w});
        }
    }

    // 2. Initialize the tracking arrays required for CSR format
    vector<int> row_ptr(v + 1, 0);
    vector<int> column(2 * e);
    vector<int> weight(2 * e);

    // 3. Convert the populated Adjacency List to CSR Format arrays
    csrGraph(adj, row_ptr, column, weight, v);
   
    // 4. Output the final generated CSR format representation arrays
    cout << "\nrow_ptr array:\n";
    for (int i = 0; i <= v; i++) {
        cout << row_ptr[i] << " ";
    }
    
    cout << "\n\ncolumn array:\n";
    for (int i = 0; i < 2 * e; i++) {
        cout << column[i] << " ";
    }
    
    cout << "\n\nweight array:\n";
    for (int i = 0; i < 2 * e; i++) {
        cout << weight[i] << " ";
    }
    cout << endl;

    krushkal(row_ptr,column,weight,v,0);

    return 0;
}
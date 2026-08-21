#include <iostream>
#include <vector>
#include <chrono>

#include "../../assignment_01/driver/csr_graph.cpp"
#include "../../assignment_01/src/csr_graph.h"


using namespace std;

void bellmanFord(vector<int>& vertex,vector<int>& child,vector<int>& weight,int v,int source);



int main(){
    char graph_mode_char;
    if (!(cin >> graph_mode_char)) {
        return 0;
    }

    bool is_undirected = (graph_mode_char == 'U' || graph_mode_char == 'u');

    vector<edgeList> edges;
    int u, v, w;
    int max_vertex_id = -1;

    while (cin >> u >> v >> w) {
        edgeList edge = {u, v, w};
        edges.push_back(edge);
        max_vertex_id = max({max_vertex_id, u, v});
    }

    if (edges.empty()) {
        return 0;
    }
    int total_vertices = max_vertex_id+1;
    CSRResult result = csrGraph(edges, max_vertex_id, is_undirected);

    auto start = chrono::high_resolution_clock::now();
    bellmanFord(result.row_ptr,result.col_idx,result.values,total_vertices,0);

    auto end = chrono::high_resolution_clock::now();
    double time = chrono::duration_cast<chrono::microseconds>(end-start).count()/1000.0;
    cout<<endl;
    cout<<"========================================";cout<<endl;
    cout<<"||  Runtime Complexity : "<<time<<"ms.      ||";cout<<endl;
    cout<<"========================================";cout<<endl;

    // cout << "\n--- CSR Graph Representation ---\n";
    // cout << "Vertex Array: ";
    // for (int i = 0; i <= v; i++) {
    //     cout << vertex[i] << " ";
    // }
    // cout << "\nChild Array:  ";
    // for (int i = 0; i < e; i++) {
    //     cout << child[i] << " ";
    // }
    // cout << "\nWeight Array: ";
    // for (int i = 0; i < e; i++) {
    //     cout << weight[i] << " ";
    // }
    // cout << endl;
}
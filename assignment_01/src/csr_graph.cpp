#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>
#include "./csr_graph.h"



using namespace std;

int main() {
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

    auto start = chrono::high_resolution_clock::now();
    CSRResult result = csrGraph(edges, max_vertex_id, is_undirected);
    auto end = chrono::high_resolution_clock::now();
    
    double time = chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0;
    for(auto i : result.row_ptr) cout<<i <<" ";
    cout<<endl;
    for(auto i : result.col_idx) cout<<i<<" ";
    cout<<endl;
    for(auto i : result.values) cout<<i<<" ";
    
    cout << endl;
    cout << endl;
    cout << "========================================" << endl;
    cout << "||  Runtime Complexity : " << time << " ms.      ||" << endl;
    cout << "========================================" << endl; 
    
    return 0;
}

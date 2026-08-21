#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>
#include "../../assignment_01/src/csr_graph.h"
#include "../../assignment_01/driver/csr_graph.cpp"
#include "../src/kruskal.h"

using namespace std;

int main() {
    char graph_mode_char;
    if (!(cin >> graph_mode_char)) {
        return 0;
    }

    bool is_undirected = (graph_mode_char == 'U' || graph_mode_char == 'u');

    vector<edgeList> edges;
    int u, input_v, w;
    int max_vertex_id = -1;

    // Read the graph until EOF stream ends
    while (cin >> u >> input_v >> w) {
        edgeList edge = {u, input_v, w};
        edges.push_back(edge);
        max_vertex_id = max({max_vertex_id, u, input_v});
    }

    if (edges.empty()) {
        return 0;
    }

    int total_vertices = max_vertex_id + 1;

    // Invoke CSR parsing script pipeline
    CSRResult csr = csrGraph(edges, max_vertex_id, is_undirected);

    vector<mstedge> mst;
    int totalweight = 0;

    auto start = chrono::high_resolution_clock::now();

    kruskal(total_vertices, csr.row_ptr, csr.col_idx, csr.values, mst, totalweight);

    auto end = chrono::high_resolution_clock::now();
    double time = chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0;

    cout << "The MST is:" << endl;
    for (auto &edge : mst) {
        cout << edge.u << " " << edge.v << " " << edge.weight << endl;
    }
    
    cout << "========================================" << endl;
    cout << "Weight : " << totalweight << " | Time : " << time << " ms." << endl;
    cout << "========================================" << endl;

    return 0;
}

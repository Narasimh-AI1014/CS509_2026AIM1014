#include <iostream>
#include <vector>
#include "../src/csr_graph.h"

using namespace std;

CSRResult csrGraph(const vector<edgeList>& edges, int max_vertex_id, bool is_undirected) {
    int v = max_vertex_id + 1;

    vector<int> degree(v, 0);
    for (const auto& edge : edges) {
        degree[edge.src]++;
        if (is_undirected) {
            degree[edge.dest]++; // Simplified logic: self-loop handles edge.src==edge.dest correctly on its own
        }
    }

    vector<int> row_ptr(v + 1, 0);
    for (int i = 0; i < v; i++) {
        row_ptr[i + 1] = row_ptr[i] + degree[i];
    }

    vector<int> temp = row_ptr;
    int total_csr_entries = row_ptr[v];
    vector<int> col_idx(total_csr_entries);
    vector<int> values(total_csr_entries);

    for (const auto& edge : edges) {
        int dest_index = temp[edge.src]++;
        col_idx[dest_index] = edge.dest;
        values[dest_index] = edge.weight;

        if (is_undirected && (edge.src != edge.dest)) {
            int src_index = temp[edge.dest]++;
            col_idx[src_index] = edge.src;
            values[src_index] = edge.weight;
        }
    }

    // Return all three vectors bundled inside the struct
    return {row_ptr, col_idx, values};
}

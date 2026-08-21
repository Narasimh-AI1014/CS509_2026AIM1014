#ifndef CSR_GRAPH_H
#define CSR_GRAPH_H

#include <vector>

struct edgeList {
    int src;
    int dest;
    int weight;
};

// 1. Make sure this struct exists in the header!
struct CSRResult {
    std::vector<int> row_ptr;
    std::vector<int> col_idx;
    std::vector<int> values;
};

// 2. Make sure this matches the return type in csr_graph.cpp
CSRResult csrGraph(const std::vector<edgeList>& edges, int max_vertex_id, bool is_undirected);

#endif 

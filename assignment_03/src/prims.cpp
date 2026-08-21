#include <bits/stdc++.h>
#include "../../assignment_01/src/csr_graph.h"
#include "../../assignment_01/driver/csr_graph.cpp"
#include"../src/prims.h"

using namespace std;
int main()
{
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
    int totalweight = 0;
    vector<mstedge> mst;
    CSRResult result = csrGraph(edges, max_vertex_id, is_undirected);

    auto start=chrono::high_resolution_clock::now();

    prim(total_vertices,result.row_ptr,result.col_idx,result.values,mst,totalweight);

    auto end=chrono::high_resolution_clock::now();
    
    double time = chrono::duration_cast<chrono::microseconds>(end-start).count()/1000.0;

    
    for(auto &edge:mst)
    {
        cout<<edge.source<<" "<<edge.destination<<" "<<edge.weight<<endl;
    }
   cout<<endl<<"Weight : "<<totalweight<< " time : "<< time<<endl;

}
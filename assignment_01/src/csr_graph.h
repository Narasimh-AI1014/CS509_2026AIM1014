#ifndef CSR_GRAPH_H
#define CSR_GRAPH_H

#include <vector>


struct edgeList {
    int src;
    int dest;
    int weight;
};


void csrGraph(std::vector<edgeList>& edges, int v, int e);

#endif 

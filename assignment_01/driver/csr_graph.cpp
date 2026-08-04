#include <iostream>
#include <vector>
#include "../src/csr_graph.h"

using namespace std;
void csrGraph(vector<edgeList>& edges,int v,int e){

    //v no.of vertices and e no.of edges

    //storing degree of a node
    vector<int> degree(v,0);
    for(auto& edge_row : edges){
        degree[edge_row.src]+=1;
    }

    // vertices array
    vector<int> arrayOfNodes(v+1,0);

    for(int i=0;i<v;i++){
        arrayOfNodes[i+1] = arrayOfNodes[i] + degree[i];
    }

    vector<int> temp = arrayOfNodes;
    
    vector<int> colIndex(edges.size());
    vector<int> weight(edges.size());
    for(auto& edge:edges){
        int dest_index = temp[edge.src]++;
        colIndex[dest_index] = edge.dest;
        weight[dest_index] =edge.weight;
    }
    

    for(int i=0;i<=v;i++){
        cout<<arrayOfNodes[i]<<"\t";
    }
    cout<<endl;
    cout<<"child : ";
    for(int i=0;i<e;i++){
        cout<<colIndex[i]<<"\t";
    }
    cout<<endl<<"weight : ";
    for(int i=0;i<e;i++){
        cout<<weight[i]<<"\t";
    }
    cout<<endl;
    return;
}
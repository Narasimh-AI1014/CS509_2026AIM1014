#include <iostream>
#include <vector>
#include "csr_graph.h"
#include <chrono>

using namespace std;




void csrGraph(vector<edgeList>& edges,int v,int e);

int main(){
    int v,e;
    cout<<"Enter the no.of vertices : ";
    cin>>v;
    cout<<endl;

    cout<<"Enter the no.of edges : ";
    cin>>e;
    cout<<endl;

    vector<edgeList> edge(e);

    for(int i=0;i<e;i++){
        cin>>edge[i].src>>edge[i].dest>>edge[i].weight;

    }

    auto start = chrono::high_resolution_clock::now();
    csrGraph(edge,v,e);
    auto end = chrono::high_resolution_clock::now();
    double time = chrono::duration_cast<chrono::microseconds>(end-start).count()/1000.0;
    cout<<endl;
    cout<<"========================================";cout<<endl;
    cout<<"||  Runtime Complexity : "<<time<<"ms.      ||";cout<<endl;
    cout<<"========================================";cout<<endl; 
    return 0;

}
#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

const int INF = 1e9;

void csrGraph(vector<vector<pair<int,int>>>& adjList, vector<int>& vertex, vector<int>& child, vector<int>& weight, int v);

void bellmanFord(vector<int>& vertex,vector<int>& child,vector<int>& weight,int v,int e,int source);
// void adjListToCSR(vector<vector<pair<int,int>>>& adjList,vector<int>& vertex,vector<int>& child,vector<int>& weight,int v){
    
//     int i=0,j=0;
//     for(i=0;i<v;i++){
//         vertex[i] = j;
//         for(auto edge : adjList[i]){
//             child[j] = edge.first;
//             weight[j] = edge.second;
//             j+=1;
//         }
//     }
//     vertex[i] = j;

// }

int main(){
    int v;
    cout<<"Enter the no.of vertices : ";
    cin>>v;

    int e;
    cout<<"Enter the no.of edges : ";
    cin>>e;

    vector<vector<pair<int,int>>> adjList(v);
    
    int undirected;
    cout<<"Enter 0 for undirected graph and 1 direct graph";
    cin>>undirected;

    

    if(undirected==0){
        for(int i=0;i<e;i++){
            int src,dest,w;
            cin>>src>>dest>>w;
            adjList[src].push_back({dest,w});
            adjList[dest].push_back({src,w});
        }
        e=2*e;
    }
    else{
        for(int i=0;i<e;i++){
            int src,dest,w;
            cin>>src>>dest>>w;
            adjList[src].push_back({dest,w});
            
        }
    }
    
    
    vector<int> vertex(v+1,0);
    vector<int> child(e,0);
    vector<int> weight(e,0);
    csrGraph(adjList,vertex,child,weight,v);

    auto start = chrono::high_resolution_clock::now();
    bellmanFord(vertex,child,weight,v,e,0);

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
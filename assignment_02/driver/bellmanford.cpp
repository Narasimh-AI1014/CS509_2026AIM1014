#include <iostream>
#include <vector>
using namespace std;

const int INF = 1e9;
void printPathSequence(int target, const vector<int>& parent) {
    if (target == -1) return;
    printPathSequence(parent[target], parent);
    cout << target << " ";
}
void bellmanFord(vector<int>& vertex,vector<int>& child,vector<int>& weight,int v,int e,int source){
    vector<int> d(v,INF);
    d[source]=0;
    

    vector<int> parent(v,-1);
    for(int k=0;k<v-1;k++){
        for(int i=0;i<v;i++){
            if(d[i] == INF)
                continue;
            for(int j=vertex[i];j<vertex[i+1];j++){
                int dest = child[j];
                int w = weight[j];

                if(d[i]+w <d[dest]){
                    d[dest] = d[i] + w;
                    parent[dest] = i;
                }
            }
        }
    }

    bool flag = false;
    for(int i=0;i<v;i++){
        if(d[i]==INF) continue;

        for(int j=vertex[i];j<vertex[i+1];j++){
            int dest = child[j];
            int w = weight[j];

            if(d[i]+w < d[dest]){
                flag = true;
                break;
            }
            
        }
        if(flag) break;
        
    }

    if(flag){
        cout<<"Negative cycle.";
        cout<<endl;
        return;
    }
    // cout << "\n--- Shortest Paths from Source " << source << " ---\n";
    // for (int i = 0; i < v; i++) {
    //     cout << "To Vertex " << i << " -> Cost: ";
    //     if (d[i] == INF) {
    //         cout << "INF | Path: No Path Exists\n";
    //     } else {
    //         cout << d[i] << " | Path: [ ";
    //         printPathSequence(i, parent); 
    //         cout << "]\n";
    //     }
    // }
}

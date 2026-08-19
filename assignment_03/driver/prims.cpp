#include <iostream>
#include <vector>
#include <queue>

#include "csrGraph.h"

using namespace std;

void prims(vector<int>& row_ptr,vector<int>& column,vector<int>& weight,int v,int source){
    vector<int> key(v,INT_MAX);
    vector<int> parent(v,-1);
    vector<bool> visited(v,false);
    
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pre_que;

    key[source] = 0;
    pre_que.push({0,source});

    int total=0;

    while(!pre_que.empty()){
        int u = pre_que.top().second;
        pre_que.pop();

        if(visited[u]) continue;

        visited[u] = true;

        for(int i= row_ptr[u];i<row_ptr[u+1];i++){
            int to = column[i];
            int w = weight[i];
            if(!visited[to] && w < key[to]){
                key[to] = w;
                parent[to] = u;
                pre_que.push({key[to],to});
            }
        }

    }
    cout << "Edge \tWeight\n";
    for (int i = 1; i < v; i++) {
        if (parent[i] != -1) {
            cout << parent[i] << " - " << i << " \t" << key[i] << "\n";
            total += key[i];
        }
    }
    cout << "Total MST Weight: " << total << endl;

}
#include"../src/prims.h"
#include <bits/stdc++.h>

using namespace std;
void prim(int v,const vector<int>&row_pointer,const vector<int>&colIndex,const vector<int>&weight,vector<mstedge>& mst,int &totalweight)
{
    priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>>pq;
    vector<bool> visited(v,false);

    vector<int> checkWeight(v,INT_MAX);
    totalweight=0;
    visited[0]=true;
    checkWeight[0] = 0;

    for(int i=row_pointer[0];i<row_pointer[1];i++){
        int next = colIndex[i];
        int nextweight = weight[i];

        if(nextweight<checkWeight[next]){
            checkWeight[next] = nextweight;
            pq.push({nextweight,0,next});
        }
    }
    while(!pq.empty() && mst.size() < v-1){
        auto[w,u,x]=pq.top();
        pq.pop();
        if(visited[x]){
            continue;
        }
        visited[x]=true;
        mst.push_back({u,x,w});
        totalweight+=w;
        for(int i=row_pointer[x];i<row_pointer[x+1];i++){
            int next=colIndex[i];
            int nextweight=weight[i];
            if(!visited[next] && nextweight < checkWeight[next]){
                checkWeight[next] = nextweight;
                pq.push({nextweight,x,next});
            }
        }
    }
}
#include <bits/stdc++.h>
using namespace std;

void graphColor(vector<int>& row_ptr,vector<int>& col_id,int n){
    vector<int> degree(n);

    for(int i=0;i<n;i++) degree[i] = row_ptr[i+1]-row_ptr[i];

    vector<int> order(n);
    for(int v=0;v<n;v++) order[v]=v;

    sort(order.begin(),order.end(),[&](int a,int b){
        if(degree[a]!=degree[b]) return degree[a]>degree[b];
        return a<b;
    });

    vector<int> color(n,-1);
    int currColor = 0;

    for(int i=0;i<n;i++){
        int v = order[i];

        if(color[v]!=-1) continue;

        color[v] = currColor;

        for(int j=i+1;j<n;j++){
            int u = order[j];
            
            if(color[u]!=-1) continue;
            
            bool flag = true;

            for(int k=row_ptr[u];k<row_ptr[u+1];k++){
                int neighbor = col_id[k];

                if(color[neighbor]==currColor){
                    flag = false;
                    break;
                }
            }
            if(flag) color[u]=currColor;
        }
        currColor+=1;
    }

    for(int i=0;i<n;i++) cout<<i<<" "<<color[i]<<endl;
    return;
}
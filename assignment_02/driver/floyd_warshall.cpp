#include <iostream>
#include <vector>
using namespace std;

void floydWarshall(vector<vector<int>>& dp,int v){
     for(int k=0;k<v;k++){
        for(int i=0;i<v;i++){
            for(int j=0;j<v;j++){
                if(dp[i][k]!=INF && dp[k][j]!=INF){
                    dp[i][j] = min(dp[i][j],dp[i][k]+dp[k][j]);
                }
            }
        }
    }

    bool flag = false;
    for(int i=0;i<v;i++){
        if(dp[i][i]<0){
            flag=true;
            break;
        }
    }

    if(flag){
        cout<<"Graph contains negative cycle";
    }

    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            if(dp[i][j]==INF)
                cout<<"INF";
            else
                cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
}
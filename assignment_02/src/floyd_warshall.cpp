#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
void floydWarshall(vector<vector<int>>& dp,int v);
const int INF = 1e9;

int main(){
    int v;
    // cout<<"Enter the no.of vertices : ";
    cin>>v;

    vector<vector<int>> dp(v,vector<int>(v,0));

    cout<<"Enter the adjacency matrix : \n";
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            cin>>dp[i][j];
        }
    }

   
    return 0;

}
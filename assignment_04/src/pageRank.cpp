#include <bits/stdc++.h>
using namespace std;
void pageRank(vector<int>& row_ptr,vector<int>& col_ind,double d,double epsilon,int max_iter,int V);
int main(){
    int V,E;

    cin>>V>>E;

    vector<int> row_ptr(V+1,0);
    vector<int> col_ind(2*E);
    
    int ind = 0;

    for(int i=0;i<V;i++){
        int u,degree;
        cin>>u>>degree;
        row_ptr[u+1] = row_ptr[u] + degree;

        for(int j=0;j<degree;j++){
            cin>>col_ind[ind++];
        }
    }

    double d,tol;
    int max_iter;
    cin>>d>>tol;
    cin>>max_iter;
    auto start=chrono::high_resolution_clock::now();

    pageRank(row_ptr,col_ind,d,tol,max_iter,V);

    auto end=chrono::high_resolution_clock::now();
    
    double time = chrono::duration_cast<chrono::microseconds>(end-start).count()/1000.0;
    return 0;
}
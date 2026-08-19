#include <bits/stdc++.h>

class DisjointSet{
    private:
        vector<int> parent;
        vector<int> size;
    public:
        DisjointSet(int n){
            parent.resize(n);
            size.resize(n,1);
            for(int i=0;i<n;i++) parent[i] = i;
        }
        
        int find(int u){
            if(u == parent[u]) return u;
            return u=find(parent[u]);
        }
        
        bool union_sets(int u,int v){
            int root_u = find(u);
            int root_v = find(v);
            
            if(root_u == root_v) return false;
            else if(size[root_u] < size[root_v]){
                parent[root_u] = root_v;
                size[root_v] +=size[root_u];
            }
            else{
                parent[root_v] = root_u;
                size[root_u] += size[root_v];
            }
            return true;
        }
    
};
int kruskalsMST(int V, vector<vector<int>> &edges) {
        // code here
        sort(edges.begin(),edges.end(),[](const vector<int>& a,
                                          const vector<int>& b){
                                              return a[2]<b[2];
                                          });
        DisjointSet dsu(V);
        int total = 0;
        vector<vector<int>> mst_edges;
        
        for(auto edge : edges){
            if(dsu.union_sets(edge[0],edge[1])){
                mst_edges.push_back(edge);
                total+=edge[2];
            }
            if(mst_edges.size() == V-1) break;
        }
        return total;
    }
};
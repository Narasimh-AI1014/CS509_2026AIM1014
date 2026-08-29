#include <bits/stdc++.h>
using namespace std;
void graphColor(vector<int>& row_ptr,vector<int>& col_id,int n);
int main(){
    int n = 5;
    vector<int> row_ptr = {0,2,5,8,10,12};
    vector<int> col_ind = {
    1, 2,
    0, 2,3,
    0, 1, 4,
    1, 4,
    2, 3
};
    graphColor(row_ptr,col_ind,n);

    return 0;
}
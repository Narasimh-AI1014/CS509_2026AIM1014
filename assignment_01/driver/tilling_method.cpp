#include <vector>
using namespace std;
vector<vector<int>> tillingMethod(const vector<vector<int>>& mat1,const vector<vector<int>>& mat2,int M,int K,int N,int blocksize){
    vector<vector<int>> result(M,vector<int>(N,0));

    for(int si=0;si<M;si+=blocksize){
        for(int sk=0;sk<K;sk+=blocksize){
            for(int sj=0;sj<N;sj+=blocksize){

                int i_end = min(blocksize+si,M);
                int k_end = min(blocksize+sk,K);
                int j_end = min(blocksize+sj,N);


                for(int i=si;i<i_end;i++){
                    for(int k=sk;k<k_end;k++){
                        int r = mat1[i][k];
                        for(int j=sj;j<j_end;j++){
                            result[i][j] += r*mat2[k][j];
                        }
                    }
                }
            }
        }
    }
    return result;
}
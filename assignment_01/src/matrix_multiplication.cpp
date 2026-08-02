#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
vector<vector<int>> matMul(const vector<vector<int>>& mat1, const vector<vector<int>>& mat2, int M, int K, int N);
int main(){
    int M,K,N;
    // MxK - Matrix 1
    // KxN - Matrix 2

    //cout<<"Enter the no.of rows in Matrix 1 : ";
    cin>>M;
    cout<<endl;

    //cout<<"Enter the no.of columns in Matrix 1 : ";
    cin>>K;
    cout<<endl;

    //cout<<"Enter the no.of rows in Matrix 2 : ";
    int x;
    cin>>x;
    cout<<endl;

    if(x!=K){
        //cout<<"Matrix multiplication not possible.";
        return 0;
    }
    //cout<<"Enter the no.of columns in Matrix 2 : ";
    cin>>N;
    cout<<endl;
    

    //Initializing matrix 1 and matrix 2
    vector<vector<int>> mat1(M,vector<int>(K,0));
    vector<vector<int>> mat2(K,vector<int>(N,0));

    //Assigning values to matrix 1
    //cout<<"Enter elements for Matrix_1 "<<M<<"x"<<K;
    for(int i=0;i<M;i++){
        for(int j=0;j<K;j++){
           cin>>mat1[i][j];
        }
    }


    //Assigning matrix 1 and matrix 2
    //cout<<"Enter elements for Matrix_2 "<<K<<"x"<<N;
    for(int i=0;i<K;i++){
        for(int j=0;j<N;j++){
            cin>>mat2[i][j];
        }
    }
    
    //Result Matrix
    vector<vector<int>> result(M,vector<int>(N));


    auto start = chrono::high_resolution_clock::now(); 
    // Matrix multiplication algorithm
    result = matMul(mat1,mat2,M,K,N);
    //cout<<"Printing the result Matrix: "<<endl;
    // for(int i=0;i<M;i++){
    //     for(int j=0;j<N;j++){
    //         cout<<result[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    auto end = chrono::high_resolution_clock::now();
    double time = chrono::duration_cast<chrono::microseconds>(end-start).count()/1000.0;
    cout<<endl;
    cout<<"========================================";cout<<endl;
    cout<<"||  Runtime Complexity : "<<time<<"ms.      ||";cout<<endl;
    cout<<"========================================";cout<<endl;

    return 0;
}
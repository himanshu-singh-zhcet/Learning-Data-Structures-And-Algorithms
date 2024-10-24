// Write a program to display multipication of two matrices entered by the user
#include<iostream>
using namespace std;
int main(){
    int A[2][2];   // first matrix
    int B[2][2];   // second matrix
    cout<<"enter te elements of first matrix:"<<endl;
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            cin>>A[i][j];
        }
    }
    cout<<"enter te elements of second matrix:"<<endl;
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            cin>>B[i][j];
        }
    }
    int M[2][2];  // MULTIPICATION MATRIX
    int ans=0;
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            ans=A[i][0]*B[0][j]+A[i][1]*B[1][j];
            M[i][j]=ans;
        }
    }
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            cout<<M[i][j]<<" ";
        }
    }
return 0;
}

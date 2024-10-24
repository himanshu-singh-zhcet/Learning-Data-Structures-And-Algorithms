// write a program to display the transpose of matrix
#include<iostream>
using namespace std;
int main(){
    cout<<"enter the rows and coloumn of a matrix"<<endl;
    int m,n;
    cin>>m>>n;
    int Matrix[m][n];
    cout<<"enter te elements of matrix:"<<endl;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>Matrix[i][j];
        }
    }
    cout<<"transpose of matrix:"<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<Matrix[j][i]<<" ";
        }
    }
    

return 0;
}
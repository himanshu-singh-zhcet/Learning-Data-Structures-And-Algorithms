#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

void rotate_matrix(vector<vector<int> > &v){
   int n = v.size();
    // transpose the matrix
    for(int i = 0;i<n;i++){
        for(int j = 0;j<i;j++){
            swap(v[i][j],v[j][i]);
        }
    }

    // reverse every row 
    for(int i =0;i<n;i++){
        reverse(v[i].begin(),v[i].end());
    }
    return;
}
int main(){
    int n;
    cout<<"enter the size of Square matrix: ";
    cin>>n;
    vector<vector<int> > vec(n,vector<int> (n));
    for(int i =0;i<n;i++){
        for(int j = 0;j<n;j++){
            cin>>vec[i][j];
        }
    }

    rotate_matrix(vec);

    for(int i =0;i<n;i++){
        for(int j = 0;j<n;j++){
            cout<<vec[i][j]<<" ";
        }
        cout<<endl;
    }
return 0;
}
#include<iostream>
#include<vector>
using namespace std;

int left_most_one(vector<vector<int> > &v){
    int left_most_ones = -1;
    int max_one_rows = -1;
    int j = v[0].size()-1;
    //  finding leftmost zeroi in 0th row 
    while(j>=0  &&v[0][j]==1){
        left_most_ones=j;
        max_one_rows=0;
        j--;

        }
    // check in rest of rows if we can find a one to the left most one 
    for(int i =1;i<v.size();i++){
        while(j>=0  &&v[i][j]==1){
        left_most_ones=j;
        max_one_rows=i;
        j--;

        }
    }
    return max_one_rows;
}

int maximum_ones_row(vector<vector<int> > &v){
    int maximum_ones = INT16_MIN;
    int maximum_ones_row  = -1;
    int coloumns = v[0].size();
    for(int i=0;i<v.size();i++){
        for(int j= 0;j<v[0].size();j++){
            if(v[i][j]==1){
                int no_of_ones = coloumns-j;
                if(no_of_ones>maximum_ones){
                    maximum_ones = no_of_ones;
                    maximum_ones_row = i;
                }
            }
        }
    }
    return maximum_ones_row;
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int> > vec(n,vector<int> (m));
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            cin>>vec[i][j];
        }
    }
    int result = maximum_ones_row(vec);
    cout<<result<<endl;
return 0;
}
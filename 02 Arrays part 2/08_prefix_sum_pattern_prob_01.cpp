#include<iostream>
#include<vector>
using namespace std;

int rectangle_sum_by_prefix_sum_over_coloumns_and_rows_both(vector<vector<int> > &matrix,int l1,int r1,int l2, int r2){
    int sum = 0;

    // prefix sum array row wise
    for(int i =0;i<matrix.size();i++){
        for(int j =1;j<matrix[0].size();j++){
            matrix[i][j]+= matrix[i][j-1];
        }
    }

    // prefix_sum_over_coloumn_wise
    for(int i =1;i<matrix.size();i++){
        for(int j =0;j<matrix[0].size();j++){
            matrix[i][j]+= matrix[i-1][j];
        }
    }

    int top_sum =0,left_sum =0,top_left_sum =0;
    if(l1!=0) top_sum = matrix[l1-1][r2];
    if(r1!=0) left_sum = matrix[l2][r1-1];
    if(l1!=0&& r1!= 0)  top_left_sum= matrix[l1-1][r1-1];

    sum = matrix[l2][r2]-top_sum-left_sum+top_left_sum;

    return sum;
}

int rectangle_sum_by_precalculating_horizontal_sum(vector<vector<int> > &matrix,int l1,int r1,int l2, int r2){
    int sum =0;

    // prefix sum array row wise
    for(int i =0;i<matrix.size();i++){
        for(int j =1;j<matrix[0].size();j++){
            matrix[i][j]+= matrix[i][j-1];
        }
    }

    for(int i =l1;i<=l2;i++){
        if(r1!=0){
            sum+= matrix[i][r2]-matrix[i][r1-1];
        }
        else{
            sum+= matrix[i][r2];
        }
    }
    return sum;
}


int rectangle_sum_by_bruteforce_approch(vector<vector<int> > &matrix,int l1,int r1,int l2, int r2){
    int sum =0;
    for(int i =l1;i<=l2;i++){
       for(int j=r1;j<=r2;j++){
          sum+= matrix[i][j];
       }
    }
    return sum;
}


int main(){
    cout<<"enter the size of matrix"<<endl;
    int n,m;
    cin>>n>>m;
    cout<<"enter the elements of matrix"<<endl;
    vector<vector<int> > vec(n,vector<int> (m));
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            cin>>vec[i][j];
        }
    }
    cout<<"enter the cordinates:"<<endl;
    int l1,r1,l2,r2;
    cin>>l1>>r1>>l2>>r2;

    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            cout<<vec[i][j]<<" ";
        }
        cout<<endl;
    }
    int sum = rectangle_sum_by_prefix_sum_over_coloumns_and_rows_both(vec,l1,r1,l2,r2);
    cout<<"the sum is: "<<sum<<endl;

return 0;
}
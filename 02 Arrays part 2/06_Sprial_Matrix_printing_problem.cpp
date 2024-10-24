#include<iostream>
#include<vector>
using namespace std;

void sprial(vector<vector<int> > &vec){
    int left = 0;
    int right = vec[0].size()-1;
    int top = 0;
    int bottom = vec.size()-1;
    
     int direction = 0;

     while(left<=right && top<=bottom){
        // left -->right
       if(direction == 0){
        for(int col = left;col<=right;col++){
            cout<<vec[top][col]<<" ";
        }
        top++;
       }
       // top to bottom 
       else if(direction == 1){
        for(int row = top;row<=bottom;row++){
            cout<<vec[row][right]<<" ";
        }
        right--;
       }
       // right to left
       else if(direction == 2){
         for (int col = right;col>=left;col--){
            cout<<vec[bottom][col]<<" ";
         }
         bottom--;
       }
       // bottom to top
       else if(direction == 3){ 
       for(int row =bottom;row>=top;row--){
        cout<<vec[row][left]<<" ";
       }
       left++;
       }
       direction = (direction+1)%4;

     }
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

    sprial(vec);
return 0;
}
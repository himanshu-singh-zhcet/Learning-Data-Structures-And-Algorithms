#include<iostream>
#include<vector>
using namespace std;

bool can_place_queen(int row,int col,vector<vector<char>> &grid){
    // is someone attacking from vertical up 
    for(int i =row-1;i>=0;i--){
        if(grid[i][col] == 'Q'){
            return false;
        }
    }

    // for checing  upper left side diagonal 
    for(int i =row-1,j=col-1;i>=0 and j>=0;i--,j--){
        if(grid[i][j] == 'Q'){
            return false;
        }
    }
   
    // for checkimg upper right side diagonal 
    for(int i =row-1,j=col+1;i>=0 and j<grid.size();i--,j++){
        if(grid[i][j] == 'Q'){
            return false;
        }
    }

    return true;
}
void nqueen(int currrow, int n, vector<vector<char>> &grid){
    if(currrow==n){
        for(int i=0;i<n;i++){
            for(int j =0;j++;j<n){
                cout<<grid[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<"****"<<endl;
    }

    for(int col =0; col<n;col++){
        // we will go to all the coloumns 
        // lets check if we can place a queen at current row and coloumn
        if(can_place_queen(currrow,n,grid)) {
            grid[currrow][col] = 'Q';
            nqueen(currrow+1,n,grid);
            grid[currrow][col] = '.';
        }
    }
}
int main(){
    int n =4;
    vector<vector<char>> grid(n,vector<char> (n,'.'));
    for(int i=0;i<n;i++){
            for(int j =0;j++;j<n){
                cout<<grid[i][j]<<" ";
            }
            cout<<endl;
        }
    nqueen(0,n,grid);
    return 0;
return 0;
}
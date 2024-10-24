#include<iostream>
#include<vector>
using namespace std;

void generate_sprial_matrix(vector<vector<int> > &vec){
    int left = 0;
    int right = vec[0].size()-1;
    int top = 0;
    int bottom = vec.size()-1;
    int i =1;
    int direction = 0;

     while(left<=right && top<=bottom){
        // left -->right
       if(direction == 0){
        for(int col = left;col<=right;col++){
           vec[top][col]=i;
           i++;
        }
        top++;
       }
       // top to bottom 
       else if(direction == 1){
        for(int row = top;row<=bottom;row++){
            vec[row][right]=i;
            i++;
        }
        right--;
       }
       // right to left
       else if(direction == 2){
         for (int col = right;col>=left;col--){
            vec[bottom][col]=i;
            i++;

         }
         bottom--;
       }
       // bottom to top
       else if(direction == 3){ 
       for(int row =bottom;row>=top;row--){
        vec[row][left]=i;
        i++;
       }
       left++;
       }
       direction = (direction+1)%4;

     }
}
int main(){
    cout<<"enter the size of square matrix"<<endl;
    int n;
    cin>>n;
    
    vector<vector<int> > vec(n,vector<int> (n));
    generate_sprial_matrix(vec);
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            cout<<vec[i][j]<<" ";
        }
    }

return 0;
}
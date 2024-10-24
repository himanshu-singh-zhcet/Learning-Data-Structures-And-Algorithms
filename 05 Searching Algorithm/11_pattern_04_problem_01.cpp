#include<iostream>
#include<vector>
using namespace std;
bool binary_search_On_matrix(vector<vector<int>> &v, int target){
    int n= v.size(); // no of rows
    int m= v[0].size(); // no of coloumn
    int low =0;
    int high=n*m-1;
    while(low<=high){
        int mid = low + (high - low) / 2;
        int x=mid/m;
        int y= mid%m;
        if(v[x][y]==target){
            return true;
        }
        else if (v[x][y]<target){
            low =mid+1;
        }
        else{
            high= mid-1;
        }
    }
    return false;

}
int main(){
    vector<vector<int>> a={{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    int target =3;
    cout<<binary_search_On_matrix(a,target);
return 0;
}
#include<iostream>
#include<vector>
using namespace std;
int square_root(int x){
        int low =1;
        int high =x;
        int ans =-1;
        
        while(low<=high){
            int mid= low+(high-low)/2;
            if(mid*mid<=x){
                ans =mid;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return ans;
        } 
    int main(){

    cout<<square_root(40)<<endl;
    cout<<square_root(400);

    return 0;
}
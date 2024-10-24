#include<iostream>
#include<vector>
using namespace std;
int binary_search(vector<int> &v){
    int n= v.size();
    int low =0;
    int high =n-1;
    int ans=-1;
    while(low<=high){
        int mid= low+(high-low)/2;
        if(v[mid]>v[mid-1]){  // increasing curve 
        ans= max(ans,mid); 
        low=mid+1;
        }
        else{
            high=mid-1;
        }
        
    }
    return ans;
}
int main(){
    vector<int> v={0,4,1,0};
    cout<<binary_search(v);
return 0;
}
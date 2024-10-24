#include<iostream>
#include<vector>
using namespace std;
int binary_search_recursive(vector<int> &v,int target,int low, int high){
    // base case 
    if(low>high )  return -1;
    int mid=low+(high-low)/2;
    if(v[mid]==target) return mid;
    if(v[mid]<target){
        return binary_search_recursive(v,target,mid+1,high);
    }
    else{
        return  binary_search_recursive(v,target,low,mid-1);
    }

}
int main(){
    int n;
    cout<<"enter the size of vector: ";
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cout<<"enter the "<<i<<"th elemnet of vector: ";
        cin>>a[i];// 2 4 5 7 15 24 45 50
    }
    int target;
    cout<<"enter the target element: ";
    cin>>target;
    int low =0;
    int high =n-1;
    int ans=binary_search_recursive(a,target,low,high);
    cout<<ans<<endl;
return 0;
}
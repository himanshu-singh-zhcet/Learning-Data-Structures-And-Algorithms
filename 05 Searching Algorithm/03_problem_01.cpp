#include<iostream>
#include<vector>
using namespace std;
int first_occurence(vector<int> &v ,int target){
    int n= v.size();
    int ans =-1;
    int low=0;
    int high =n-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(v[mid]==target){
            ans =mid;
            high=mid-1;

        }
        else if(v[mid]<target){
        low=mid+1;
        }
        else{
            high =mid-1;
        }
    }
    return ans;
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
    int ans=first_occurence(a,target);
    cout<<ans<<endl;
return 0;
}
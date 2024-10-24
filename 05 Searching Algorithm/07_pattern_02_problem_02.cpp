#include<iostream>
#include<vector>
using namespace std;
int binary_search_on_sorted_rotated_array(vector<int> &v,int target){
    int n=v.size();
    int low=0;
    int high= n-1;
    while(low <= high){
        int mid= low+(high-low)/2;
        if(v[mid]==target)  return mid;
        if(v[mid]>= v[low]){
            if(target >= v[low] and target <=v[mid]){
                high = mid-1;
            }
            else{
                low =mid+1;
            }
        }
        else{
            if(target>=v[mid] and target<=v[high]){
                low =mid+1;
            }
            else{
                high=mid-1;
            }
        }

        
    }
    return -1;
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
    int ans=binary_search_on_sorted_rotated_array(a,target);
    cout<<ans<<endl;
return 0;
}
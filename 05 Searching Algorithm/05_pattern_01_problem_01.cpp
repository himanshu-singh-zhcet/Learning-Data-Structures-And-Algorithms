#include<iostream>
#include<vector>
using namespace std;
int first_occurence(vector<int> v1, int target){
    int low =0;
    int ans =-1;
    int n = v1.size();
    int high  =n-1;
    while (low<=high){
        int mid=low+(high-low)/2;
        if(v1[mid]==target){
            ans =mid;
            high=mid-1;
        }
        else if(v1[mid]>target){
            high=mid-1;
        }
        else{
            low=mid+1;
        }

    }
    return ans;
}
    int last_occurence(vector<int> v1, int target){
    int low =0;
    int ans =-1;
    int n = v1.size();
    int high  =n-1;
    while (low<=high){
        int mid=low+(high-low)/2;
        if(v1[mid]==target){
            ans =mid;
            low=mid+1;
        }
        else if(v1[mid]>target){
            high=mid-1;
        }
        else{
            low=mid+1;
        }

    }
    return ans;

}
int main(){
    vector<int> v ={1,2,3,3,3,5,11};
    cout<<first_occurence(v,3)<<endl;;
    cout<<last_occurence(v,3);
    
return 0;
}

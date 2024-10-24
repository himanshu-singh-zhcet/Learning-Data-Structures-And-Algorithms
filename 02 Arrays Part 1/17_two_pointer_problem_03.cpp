// Given an integer array, sorrted in non decreasing order, return an array of squares of each number sorted in non decreaseing order
#include<iostream>
#include<vector>
using namespace std;
void sorted_square_array(vector<int> &v1){
    int left=0;
    int right=v1.size()-1;
    vector<int> ans;
    while(left<=right){
        if(abs(v1[left])<abs(v1[right])){
            ans.push_back(v1[right]*v1[right]);
            right--;
        }
        else{
            ans.push_back(v1[left]*v1[left]);
            left++;
        }
    }
    // sort the ans array
    for(int i=0;i<v1.size();i++){
        cout<<ans[i]<<" ";

    }
}
int main(){
    cout<<"enter the size of array: ";
    int n;
    cin>>n;
    vector<int> v;
    for(int i=0;i<n;i++){
        int ele;
        cin>>ele;
        v.push_back(ele);
    }
    sorted_square_array(v);
return 0;
}

// Rotate the given array by k steps, where k can be greator then the length of array 
#include<iostream>
using namespace std;
int main(){
    int arr[]={2,4,6,8,5};
    int arr_new[5];
    int n=5;  // n is the length of array
    int k=2;
    k=k%n;
    int j =0;
    for(int i=k;i<5;i++){
        arr_new[j++]=arr[i];
    }
    
    for (int i = 0; i < n-k; i++) {
        arr_new[j++]=arr[i];
    }

    for(int i =0;i<5;i++){
        cout<<arr_new[i]<<" ";
    }  
    
return 0;
}


/*
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int size = nums.size();
        k=k%size;
        reverse(nums.begin(),nums.end());
        reverse(nums.begin(),nums.begin()+k);
        reverse(nums.begin()+k,nums.end());
    }
};

*/
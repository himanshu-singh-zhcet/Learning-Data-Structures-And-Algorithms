// Find the sum of values of array {2,3,5,10,1}
#include<iostream>
using namespace std;
int sum(int *arr, int idx,int n){
    // base case 
    if(idx==n-1){
        return arr[idx];
    }
    return arr[idx]+sum(arr, idx+1,n);
}
int main(){
    int arr[]={2,3,5,10,1};
    int n=5;
    int result;
    result =sum(arr,0,n);
    cout<<"te sum of arra is: "<<result;
return 0;
}
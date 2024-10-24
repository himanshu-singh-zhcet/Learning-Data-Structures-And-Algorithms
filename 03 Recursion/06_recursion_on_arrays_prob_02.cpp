// print the max value of the given array {3,10,3,2,5}
#include<iostream>
using namespace std;
int f(int *arr,int idx,int n){
    // base case 
    if(idx ==n-1) {
        // we have only one element left so it is the maximiun
        return arr[idx];
    }
    return max(arr[idx],f(arr,idx+1,n));
}
int main(){
    int n=5;
    int arr[]={13,10,3,2,5};
    cout<<f(arr,0,n);
return 0;
}
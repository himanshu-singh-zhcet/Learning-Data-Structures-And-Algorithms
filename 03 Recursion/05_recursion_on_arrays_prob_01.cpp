// given an array print all the elements of array recusively
#include<iostream>
using namespace std;
void f(int *arr,int idx,int n){
    // base case 
    if(idx==n) return ;
    // self work
    cout<<arr[idx]<<endl;
    f(arr,idx+1,n);
}
int main(){
    int n=5;  // array length
    int arr[]={6,1,9,3,2};
    f(arr,0,5);

return 0;
}
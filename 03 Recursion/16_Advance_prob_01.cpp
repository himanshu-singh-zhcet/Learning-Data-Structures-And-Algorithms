#include<iostream>
using namespace std;

bool f(int *arr, int i, int n , int te){
    // base case
    if(i==n){
        return false;
    }

    return (arr[i] ==te) || f(arr,i+1,n,te);
}
int main(){
    int arr[] = {4,12,54,14,3,8,6,1};
    int n =8;
    int te =14;
    cout<<f(arr,0,n,te);
return 0;
}
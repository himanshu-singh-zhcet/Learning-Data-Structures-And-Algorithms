// check the given array is sorted or not
#include<iostream>
using namespace std;
int main(){
    int arr[]={1,2,3,4,5,6};
    int count=0;
    for(int i=1;i<=6;i++){
        if(arr[i]>arr[i-1]){
            count++;
        }
        else{}
    }
    if(count==5){
        cout<<"it is sorted array";
    }
    else{
        cout<<"it is not a sorted array";
    }
return 0;
}

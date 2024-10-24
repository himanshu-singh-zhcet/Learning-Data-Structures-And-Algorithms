// Find the maximum value out of all the elements in the array
#include<iostream>
using namespace std;
int main(){
    int arr[]={5,8,3,16,6,9};
    int length=sizeof(arr)/sizeof(arr[0]);
    int max =0;
    for(int i =0;i<length;i++){
    if(arr[i]>max){
        max =arr[i];
    }
    else{}
    }
    cout<<max<<endl;    
return 0;
}
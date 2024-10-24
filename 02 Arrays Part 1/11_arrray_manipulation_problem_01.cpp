// Find the unique no in a given array Where all the elements are being repeated twice with one value being unique
#include<iostream>
using namespace std;
int main(){
    int arr[]={2,3,1,3,2,4,1};
    for(int i=0;i<7;i++){
        for(int j=1+i;j<7;j++){
            if(arr[i]==arr[j]){
                arr[i]=-1;
                arr[j]=-1;
            }
        }
    }
    for(int i =0;i<7;i++){
        cout<<arr[i];
    }
return 0;
}
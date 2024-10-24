#include<iostream>
using namespace std;
int main(){
    int arr1[]={5,8,10};
    int arr2[]={2,7,8};
    int n1 = sizeof(arr1)/sizeof(arr1[0]);
    int n2 = sizeof(arr2)/sizeof(arr2[0]);
    int n3 = n1+n2;
    int arr3[n3];
    int i=0,j=0,k=0;
    while(i<n1 and j<n2){
        if(arr1[i]<arr2[j]){
            arr3[k++]=arr1[i++];
        }
        else{
            arr3[k++]=arr2[j++];
        }
    }

    while(i<n1){
        arr3[k++]=arr1[i++];
    }

    while(j<n2){
        arr3[k++]=arr2[j++];
    }


    for(int i =0;i<n3;i++){
        cout<<arr3[i]<<" ";
    }

return 0;
}

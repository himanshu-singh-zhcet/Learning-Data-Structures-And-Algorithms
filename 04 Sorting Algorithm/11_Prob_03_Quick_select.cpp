#include<iostream>
using namespace std;

int partition(int arr[],int l,int r){
    int pivot=arr[r];
    int i =l;
    int j=l;
    for(;j<r;j++){
        if(arr[j]<pivot){
            swap(arr[i],arr[j]);
             i++;
        }
    }
    // now i is pointing to the last leemnt less than pivot
    swap(arr[i],arr[r]);
    return i;
}


int  kth_smallest(int arr[],int l,int r,int k){
    if(k>0 and k<=r-l+1){
        int pos = partition(arr,l,r); // position of pivot element 
        if(pos-l==k-1){
            return arr[pos];
        }
        else if(pos-l>k-1){
            return kth_smallest(arr,l,pos-1,k);
        }
        else{
            return kth_smallest(arr,pos+1,r,k-pos+l-1);
        }
    }
    return 0;
}
int main(){
    int arr[]={3,5,2,1,4,7,8,6};
    int n=  sizeof(arr)/sizeof(arr[0]);
    int k =5;
    cout<<kth_smallest(arr,0,n-1,k);
return 0;
}
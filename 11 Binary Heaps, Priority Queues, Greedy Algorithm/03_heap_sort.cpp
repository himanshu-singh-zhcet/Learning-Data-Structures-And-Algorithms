#include<iostream>
using namespace std;
const int N = 1e3;

void max_heapify(int arr[], int size, int curr){
    while(2*curr <= size){
    int leftchild = 2*curr;
    int rightchild = 2*curr+1;
    int maxchild = leftchild;
    if(rightchild<=size and arr[rightchild]>arr[leftchild]){
        maxchild = rightchild;
    }
    if(arr[maxchild]<=arr[curr]){
        return;
    }

    swap(arr[maxchild],arr[curr]);
    curr = maxchild;
    } 
}

void remove(int arr[], int &size){
    swap(arr[1],arr[size]);
    size--;
    max_heapify(arr,size,1);
}

void heapsort(int arr[],int n){
    // step 1 heapify all parent node into maxheap
    for(int i =n/2;i>0;i--){
        max_heapify(arr,n,i);
    }

    // step 2 keep deleting elements from max heaps until size becomes zero 
    while(n>0){
        remove(arr,n);
    }

}
int main(){
    int arr[N] = {-1,60,10,80,50,5,20,70};
    int size = 7;
    heapsort(arr,size);
    for(int i =1;i<=size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
return 0;
}

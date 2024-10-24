#include<iostream>
using namespace std;
const int N = 1e3;

void min_heapify(int arr[], int &size, int curr){  
    while(2*curr <= size){
    int leftchild = 2*curr;
    int rightchild = 2*curr+1;
    int minchild = leftchild;
    if(rightchild<=size and arr[rightchild]<arr[leftchild]){
        minchild = rightchild;
    }
    if(arr[minchild]>=arr[curr]){
        return;
    }

    swap(arr[minchild],arr[curr]);
    curr = minchild;
    }
    
}

void max_heapify(int arr[], int &size, int curr){
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

int main(){
    int arr[N] = {-1,60,10,80,50,5,20,70};
    int size = 7;
    for(int i = size/2;i>0;i--){
        // i parent node
        min_heapify(arr,size,i);
    }
    for(int i =1;i<=size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}
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

void remove(int arr[], int &size){
    swap(arr[1],arr[size]);
    size--;
    min_heapify(arr,size,1);
}

int sum_elements(int arr[],int size,int k1,int k2){
    int sum =0;
    int k= k2-k1-1;
    for(int i= size/2;i>0;i--){
      min_heapify(arr,size,i);
    }
    
    while(k1--){
        remove(arr,size);
    }
    
    while(k--){
        sum= sum+arr[1];
        remove(arr,size);
    }
    return sum;
}

int main(){
    int arr[N] = {-1,7,10,4,3,20,15};
    int size = 6;
    int k1 =2;
    int k2 =5;
    cout<<sum_elements(arr,size,k1,k2);

return 0;
}
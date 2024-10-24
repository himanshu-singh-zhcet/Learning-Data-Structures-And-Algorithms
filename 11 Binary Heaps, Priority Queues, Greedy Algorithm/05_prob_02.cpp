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

int kth_smallest_element(int arr[],int size,int k){
    for(int i= size/2;i>0;i--){
      min_heapify(arr,size,i);
    }
    k = k-1;
    while(k--){
        remove(arr,size);
    }

    return arr[1];
}

int main(){
    int arr[N] = {-1,7,10,4,3,20,15};
    int size = 6;
    int k =3;
    cout<<kth_smallest_element(arr,size,k);

return 0;
}
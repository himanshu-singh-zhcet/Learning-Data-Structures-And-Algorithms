#include<iostream>
using namespace std;
const int N = 1e3;
void insert_in_minheap(int minheap[],int &size,int value){
    size++;
    minheap[size] = value;
    int curr = size;
    while(curr/2 >0 && minheap[curr/2]>minheap[curr]){
        swap(minheap[curr/2],minheap[curr]);
            curr = curr/2;
            }
}

void insert_in_maxheap(int maxheap[],int &size1,int value1){
    size1++;
    maxheap[size1] = value1;
    int curr = size1;
    while(curr/2 >0 && maxheap[curr/2]<maxheap[curr]){
        swap(maxheap[curr/2],maxheap[curr]);
        curr = curr/2;
    }
}

void remove_minheap(int minheap[],int &size){
    minheap[1] = minheap[size];
    size--;
    int curr = 1;
    while(2*curr <= size ){ // looping till curr nodes has child nodes 
       int leftchild = 2*curr;
       int rightchild = 2*curr+1;  
       int minchild = leftchild;
       if(rightchild<=size && minheap[rightchild]<minheap[leftchild]){
        minchild = rightchild;
       }
       if(minheap[minchild]>=minheap[curr]){
        return;
       }
       swap(minheap[minchild],minheap[curr]);
       curr= minchild;

    }
}
int main(){
int minheap[N] = {-1,10,20,30,40,50};
int size = 5;
int value = 5;
insert_in_minheap(minheap,size,value);
remove_minheap(minheap,size);
int maxheap[N] = {-1,60,50,40,30,20,30,10};
int size1 =7;
int value1 = 100;
insert_in_maxheap(maxheap,size1,value1);
for(int i =0;i<=size;i++){
    cout<<minheap[i]<<" ";
}
cout<<endl;

for(int i =0;i<=size1;i++){
    cout<<maxheap[i]<<" ";
}
return 0;
}
// Given an integer array ,return the prefix sum in the same array withhout creating a new array
#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> v;
    v={1,2,3,4,5};
    int a=0;
    for(int i=0;i<5;i++){
        v[i]=v[i]+a;
        a=v[i];
    }
    for(int i=0;i<5;i++){
        cout<<v[i]<<" ";
    }
return 0;
}
#include<iostream>
#include<vector>
using namespace std;
void bubble_sort(vector<int> &v1){
    int n=v1.size();
    for(int i=0;i<n-1;i++){
        int min_idx=i;
        for(int j=i+1;j<n;j++){
            if(v1[j]<v1[min_idx]){
                min_idx=j;
            }
        }
        if(min_idx!=i){
          swap(v1[i],v1[min_idx]);
        }
    }
    return;
}
int main(){
    int n;
    cout<<"enter te size of vector: ";
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cout<<"enter the "<<i<<"th elemnet of vector: ";
        cin>>v[i];
    }
    bubble_sort(v);
    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }
return 0;
}
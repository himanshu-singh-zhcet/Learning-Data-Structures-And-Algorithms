#include<iostream>
#include<vector>
using namespace std;
void bubble_sort(vector<int> &v1){
    int n=v1.size();
    for(int i=0;i<n-1;i++){
        bool flag= false;
        for(int j=0;j<n-i-1;j++){
            if(v1[j]>v1[j+1]){
                flag = true;
                swap(v1[j],v1[j+1]);
            }
        }
        if(!flag) break;
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
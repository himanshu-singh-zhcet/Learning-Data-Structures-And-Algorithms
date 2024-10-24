#include<iostream>
#include<vector>
using namespace std;
void count_sort(vector<int> &v){
    int n=v.size();
    // find the max elemnet
    int max_ele=0;
    for(int i=0;i<n;i++){
        max_ele=max(v[i],max_ele);
    }
    // create thr freq array
    vector<int> freq(max_ele+1,0);
    for(int i=0;i<n;i++){
        freq[v[i]]++;
    }
    // create commulative frequency 
    for(int i=1;i<=max_ele;i++){
        freq[i]+=freq[i-1];
    } 
    // calculate te sorted array 
    vector<int> ans(n);
    for(int i=n-1;i>=0;i--){
        ans[--freq[v[i]]]=v[i];
    }
    // copy back te answer to te original array
    for(int i=0;i<n;i++){
        v[i]=ans[i];
    }


}
int main(){
    int n;
    cout<<"enter te size of vector: ";
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cout<<"enter the "<<i<<"th elemnet of vector: ";
        cin>>a[i];
    }
    count_sort(a);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
return 0;
}
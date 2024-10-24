#include<iostream>
#include<vector>
using namespace std;
void count_sort(vector<int> &v, int pos){
    cout<<"jk";
    int n=v.size();
    //creating frequency array
    vector<int> freq(10,0);
    for(int i =0;i<n;i++){
        freq[(v[i]/pos)%10]++;
    }
    // commulative frequency
    for(int i=0;i<10;i++){
        freq[i]+=freq[i-1];
    }
    cout<<" kk";
    // ans array
    vector<int> ans(n);
    for(int i=n-1;i>=0;i--){
        ans[--freq[(v[i]/pos)%10]]=v[i];
    }
    cout<<"kh";
    // copy back te answer to te original array
    for(int i=0;i<n;i++){
        v[i]=ans[i];
    }
    cout<<"kl";
}
void radix_sort(vector<int> &v){  
    // finding maximum element in a  array
    cout<<"ii";
    int max_element=0;
    for(auto x:v){
        max_element=max(x,max_element);
    }
    for(int pos =1;max_element/pos>0;pos*=10){
        count_sort(v,pos);
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
    radix_sort(a);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
return 0;
}
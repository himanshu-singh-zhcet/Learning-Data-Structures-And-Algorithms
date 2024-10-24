#include<iostream>
#include<queue>
using namespace std;

int kth_largest_element(vector<int> a,int n ,int k){
     priority_queue<int,vector<int>, greater<int>> pq;   // min heap
     for(int i =0;i<n;i++){
        pq.push(a[i]);
        if(pq.size()>k){
            pq.pop();
        }
     }
     return pq.top();
}
int main(){
    int n,k;
    cout<<"enter the size of vector and value of k: "<<endl;
    cin>>n>>k;
    vector<int> a(n);
    cout<<"enter the elements of vector: "<<endl;
    for(int i =0;i<n;i++){
        cin>>a[i];
    }
    cout<<"the kth largest element is: "<<kth_largest_element(a,n,k)<<endl;
return 0;
}
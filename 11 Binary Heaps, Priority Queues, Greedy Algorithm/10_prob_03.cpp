#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int largest_point(vector<int> a,int size, int k){
    priority_queue<int,vector<int>, greater<int>> pq;
    for(int i =0;i<size;i++){
    pq.push(a[i]);
    }
    while(k--){
        int n1 = pq.top();
        pq.pop();
        int n2 = pq.top();
        pq.pop();
        int p = n1*n2;
        pq.push(p);
    }
    
    while(pq.size()>1){
        pq.pop();
    }
    return pq.top();
}
int main(){
    int n,k;
    cout<<"enter the value of n and k: "<<endl;
    cin>>n>>k;
    vector<int> a(n);
    cout<<"enter the elements of vector"<<endl;
    for(auto &x:a){
        cin>>x;
    }
    cout<<"the largest point is: ";
    
    cout<<largest_point(a,n,k);
return 0;
}
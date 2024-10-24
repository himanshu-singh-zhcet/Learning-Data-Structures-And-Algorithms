#include<iostream>
#include<queue>
using namespace std;
int main(){
    priority_queue<int>  pq1;  // max heap
    pq1.push(4);
    pq1.push(7);
    pq1.push(2);
    pq1.push(10);
    cout<<"minheap: "<<endl;
    while (!pq1.empty())
    {
       cout<<pq1.top()<<" ";
       pq1.pop();
    }
    cout<<endl;

    priority_queue<int,vector<int>,greater<int>> pq2; // min heap 
    pq2.push(4);
    pq2.push(7);
    pq2.push(2);
    pq2.push(10);
    cout<<"maxheap: "<<endl;
    while (!pq2.empty())
    {
       cout<<pq2.top()<<" ";
       pq2.pop();
    }
    cout<<endl;
    
return 0;
}
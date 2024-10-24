#include<iostream>
#include<queue>
using namespace std;

vector<pair<int,int>> k_closest_points(vector<pair<int,int>> pts, int n, int k){
    priority_queue<pair<int,pair<int,int>>> pq; // maxheap 
    for(auto &pt: pts){
    int distance = pt.first+pt.second;
    pq.push(make_pair(distance,pt));
    if(pq.size()>k){
        pq.pop(); 
    }
    }

    vector<pair<int,int>> ans(k);
    while(!pq.empty()){
        ans[pq.size()-1] = pq.top().second;
        pq.pop();
    }
    return ans;
}
int main(){
    int n,k;
    cout<<"enter the size of vector and value of k: "<<endl;
    cin>>n>>k;
    vector<pair<int,int>> pts(n);
    for(auto &pt: pts){
        cin>>pt.first>>pt.second;
    }
    vector<pair<int,int>> anspts = k_closest_points(pts,n,k);
    for( auto &pt: anspts){
        cout<<pt.first<<" "<<pt.second<<endl;
    }
return 0;
}
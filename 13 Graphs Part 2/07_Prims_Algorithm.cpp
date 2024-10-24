#include<bits/stdc++.h> 
using namespace std;
#define long        long long int
#define pp          pair<int,int>
vector<list<pair<int,int>>> gr;
void add_edge(int u, int v,int wt, bool bidir = true){
    gr[u].push_back({v,wt});
    if(bidir) {
        gr[v].push_back({u,wt});
    }
}

long prims(int src,int n){
    priority_queue<pp,vector<pp>,greater<pp>> pq; //  {wt,node}
    unordered_set<int> vis;
    vector<int> par(n+1);
    unordered_map<int,int> mp;
    for(int i =1;i<=n;i++){
        mp[i] = INT_MAX;
    }
    pq.push({0,src});
    mp[src] = 0;
    int total_count = 0;  // 0  -->  n-1 edges
    int result = 0; // sum of weights
    while(total_count<n and !pq.empty()){
        pp curr = pq.top();
        if(vis.count(curr.second)){
            pq.pop();
            continue;
        }
        vis.insert(curr.second);
        total_count++;
        result+= curr.first;
        pq.pop();
        for(auto neighbour: gr[curr.second]){
            if(!vis.count(neighbour.first) and mp[neighbour.first] > neighbour.second){
                pq.push({neighbour.second,neighbour.first});
                par[neighbour.first] = curr.second;
                mp[neighbour.first] = neighbour.second;
            }
        }
    }
    return result;
}
int main(){
    int n, e; // n = no of vertices, e = no of edges
    cout<<"enter the no of vertices and edges: "<<endl;
    cin>>n>>e;
    gr.resize(n+1, list<pair<int,int>> ());  // yhaa n+1c isliye hai kyuki 1 based indexing hai
    cout<<"enter the u,v,wt of edges:"<<endl;
    while(e--){
        int u,v,wt;
        cin>>u>>v>>wt;
        add_edge(u,v,wt);
    }
    
    int src;
    cout<<"enter the source: "<<endl;
    cin>>src;
    cout<<prims(src,n);


return 0;
}
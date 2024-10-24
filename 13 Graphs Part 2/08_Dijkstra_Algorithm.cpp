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

unordered_map<int,int> dijkstra(int src,int n){
    priority_queue<pp,vector<pp>,greater<pp>> pq; //  {wt,node}
    unordered_set<int> vis;
    vector<int> via(n);
    unordered_map<int,int> mp;
    for(int i =0;i<n;i++){
        mp[i] = INT_MAX;
    }
    pq.push({0,src});
    mp[src] = 0;
    while(!pq.empty()){
        pp curr = pq.top();
        if(vis.count(curr.second)){
            pq.pop();
            continue;
        }
        vis.insert(curr.second);
        pq.pop();
        for(auto neighbour: gr[curr.second]){
            if(!vis.count(neighbour.first) and mp[neighbour.first] >mp[curr.second]+neighbour.second){
                pq.push({mp[curr.second]+neighbour.second,neighbour.first});
                via[neighbour.first] = curr.second;
                mp[neighbour.first] = mp[curr.second]+neighbour.second;
            }
        }
    }
    return mp;
}
int main(){
    int n, e; // n = no of vertices, e = no of edges
    cout<<"enter the no of vertices and edges: "<<endl;
    cin>>n>>e;
    gr.resize(n, list<pair<int,int>> ());
    cout<<"enter the u,v,wt of edges:"<<endl;
    while(e--){
        int u,v,wt;
        cin>>u>>v>>wt;
        add_edge(u,v,wt);
    }
    
    int src;
    cout<<"enter the source: "<<endl;
    cin>>src;
    
    unordered_map<int,int> sp = dijkstra(src,n);

    int dest;
    cout<<"enter the destination: "<<endl;
    cin>>dest;
    cout<<"the sortest path is: "<<endl;
    cout<<sp[dest];
    return 0;
}
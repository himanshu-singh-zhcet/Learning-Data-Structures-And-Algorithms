#include<iostream>
#include<vector>
#include<list>
#include<unordered_set>
#include<queue>
using namespace std;

vector<list<int>> graph;
unordered_set<int> visited;
int v;    // no of vertices
void add_edge(int src, int dest, bool bi_dir = true){
    graph[src].push_back(dest);
    if(bi_dir){
        graph[dest].push_back(src);
    }
}

void bfs(int src, vector<int> &dist){
    queue<int> qu;
    visited.clear();
    dist.resize(v,INT8_MAX);
    dist[src]=0;
    visited.insert(src);
    qu.push(src);
    while(! qu.empty()){
        int curr = qu.front();
        cout<<curr<<" ";
        qu.pop();
        for(auto neighbour: graph[curr]){
            if(not visited.count(neighbour)){
                qu.push(neighbour);
                visited.insert(neighbour);
                dist[neighbour] = dist[curr]+1;
            }
        }
    }
    cout<<endl;
}
int main(){
    cout<<"enter the no vertex: ";
    cin>>v;
    graph.resize(v, list<int> ());
    cout<<"enter the no edges: ";
    int e;
    cin>>e;
    while(e--){
        int s,d;
        cin>>s>>d;
        add_edge(s,d);   // for directed graph we have to pass here false
    }
    int x;
    cout<<"enter the value of source"<<endl;
    cin>>x;
    vector<int> dist;
    bfs(x,dist);
    for(int i =0;i<dist.size();i++){
        cout<<dist[i]<<" ";
    }
    
   
return 0;
}
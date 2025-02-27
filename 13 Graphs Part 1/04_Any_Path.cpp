#include<iostream>
#include<vector> 
#include<list>
#include<unordered_set>
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

bool dfs(int curr, int end){
    if(curr == end) return true; 
    visited.insert(curr); // mark visited
    for(auto neighbour: graph[curr]){
        if(not visited.count(neighbour)){
            bool result = dfs(neighbour,end);
            if(result) return true;
        }
    }
    return false;
}

bool any_path(int src, int dest){
    return dfs(src,dest);
}

int main(){
    cout<<"enter the no vertex: ";
    cin>>v;
    graph.resize(v, list<int> ());
    cout<<"enter the no edges: ";
    int e;
    cin>>e;
    visited.clear();
    while(e--){
        int s,d;
        cin>>s>>d;
        add_edge(s,d,false);   // for directed graph we have to pass here false
    }
    cout<<"enter the source and destination "<<endl;
    int x,y;
    cin>>x>>y;
    cout<<any_path(x,y);
return 0;
}
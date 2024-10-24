#include<iostream>
#include<vector>
#include<list>
#include<unordered_set>
using namespace std;

vector<list<int>> graph;
int v;    // no of vertices
void add_edge(int src, int dest, bool bi_dir = true){
    graph[src].push_back(dest);
    if(bi_dir){
        graph[dest].push_back(src);
    }
}

void dfs(int node, unordered_set<int> &visited){
    visited.insert(node);
    for(auto neighbour: graph[node]){
        if(not visited.count(neighbour)){
            dfs(neighbour,visited);
        }
    }
}
int connected_components(){
    int result=0;
    unordered_set<int> visited;  // we can make this set as global
    for(int i = 0;i<v;i++){
        // go to every vertex
        // if form a vertex we can intialize, we got one more connected component 
        if(visited.count(i)==0){
            result++;
            dfs(i,visited);
        }
    }
    return result;
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
        add_edge(s,d,false);   // for directed graph we have to pass here false
    }
   cout<<connected_components()<<endl;
return 0;
}
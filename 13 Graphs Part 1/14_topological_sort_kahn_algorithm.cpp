#include<bits/stdc++.h>
using namespace std;

vector<list<int>> graph;
int v;    // no of vertices
void add_edge(int src, int dest, bool bi_dir = true){
    graph[src].push_back(dest);
    if(bi_dir){
        graph[dest].push_back(src);
    }
}
void topobfs(){
    // kahn algorithm
    vector<int> indegree(v,0);
    for(int i = 0;i<v;i++){
        for(auto neighbour: graph[i]){
            // i --->neighbour
            indegree[neighbour]++;
        }
    }
    queue<int> qu;
    unordered_set<int> vis;
    for(int i =0;i<v;i++){
        if(indegree[i]==0){
            qu.push(i);
            vis.insert(i);
        }
    }
    while (not qu.empty()){
    int node = qu.front() ;
    cout<<node<<" ";
    qu.pop();
    for(auto neighbour: graph[node]){
        if(not vis.count(neighbour)){
            indegree[neighbour]--;
            if(indegree[neighbour]==0){
                qu.push(neighbour);
                vis.insert(neighbour);
            }
        }
    }
    }
    

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
    topobfs();
return 0;
}
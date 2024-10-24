#include<iostream>
#include<vector>
#include<list>
#include<unordered_set>
using namespace std;


vector<list<int>> graph;
unordered_set<int> visited;
vector<vector<int>> result;
int v;    // no of vertices
void add_edge(int src, int dest, bool bi_dir = true){
    graph[src].push_back(dest);
    if(bi_dir){
        graph[dest].push_back(src);
    }
}

void dfs(int curr, int end, vector<int> &path){
    if(curr == end){
        path.push_back(curr);
        result.push_back(path);
        path.pop_back();
        return;
    }
    visited.insert(curr); // mark visited
    path.push_back(curr);
    for(auto neighbour: graph[curr]){
        if(not visited.count(neighbour)){
            dfs(neighbour,end,path);  
        }
    }
    path.pop_back();
    visited.erase(curr);
    return;
}

void all_path(int src, int dest){
    vector<int> v;
    dfs(src,dest,v);
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
        add_edge(s,d);   // for directed graph we have to pass here false
    }
    cout<<"enter the source and destination "<<endl;
    int x,y;
    cin>>x>>y;
    all_path(x,y);
    for(auto path: result){
        for(auto ele: path){
            cout<<ele<<", ";
        }
        cout<<endl;
    }
return 0;
}
#include<iostream>
#include<vector>
#include<list>
using namespace std;

vector<list<pair<int,int>>> graph;
void add_edge(int src, int dest,int wt, bool bi_dir = true){
    graph[src].push_back({dest,wt});
    if(bi_dir){
        graph[dest].push_back({src,wt});
    }
}

void display()   {
    for(int i =0;i<graph.size();i++){
        cout<<i<<" --> ";
        for(auto ele: graph[i]){
            cout<<"("<<ele.first<<","<<ele.second<<")"<<", ";
        }
        cout<<endl;

    }
}
int main(){
    int v;    // no of vertices
    cout<<"enter the no vertex: ";
    cin>>v;
    graph.resize(v, list<pair<int,int> > ());
    cout<<"enter the no edges: ";
    int e;
    cin>>e;
    while(e--){
        int s,d,wt;
        cin>>s>>d,wt;
        add_edge(s,d,wt);   // for directed graph we have to pass here false
    }
    display();
return 0;
}
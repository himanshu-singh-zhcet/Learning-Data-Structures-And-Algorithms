#include<iostream>
#include<vector>
#include<list>
using namespace std;

vector<list<int>> graph;
// int v;    // no of vertices
void add_edge(int src, int dest, bool bi_dir = true){
    graph[src].push_back(dest);
    if(bi_dir){
        graph[dest].push_back(src);
    }
}

void display()   {
    for(int i =0;i<graph.size();i++){
        cout<<i<<" --> ";
        for(auto ele: graph[i]){
            cout<<ele<<", ";
        }
        cout<<endl;

    }
}
int main(){
    int v;    // no of vertices
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
    display();
return 0;
}
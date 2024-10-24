#include<bits/stdc++.h>
using namespace std;
#define long         long long int

int find(vector<int> &parent, int a){
    return parent[a] = ((parent[a]==a)? a: find(parent, parent[a]));
}

void Union(vector<int> &par, vector<int> &rank, int a, int b){
    a = find(par,a);
    b = find(par,b);
    if(a==b){
        return ;
    }
    if(rank[a] >= rank[b]){
        rank[a]++;
        par[b]= a;
    }
    else{
        rank[b]++;
        par[a] = b;
    }
}

struct Edge{
    int src;
    int dest;
    int wt;
};

bool cmp(Edge e1, Edge e2){
    return e1.wt < e2.wt;
}


long kruskals(vector<Edge> &input, int n , int e){ // here n is the no of vertices and e is no of edges
    sort(input.begin(),input.end(),cmp);  // TC -   O(eloge)
    vector<int> parent(n+1);
    vector<int> rank(n+1,1);
    for(int i = 0;i<n;i++){
        parent[i]=i;
    }
    int edgecount = 0;  // tree banane ke liye exactly n-1 edges chahiye , here n is the no of edges
    int i = 0;
    long ans  = 0;
    while(edgecount<n-1 and i<input.size()){  // TC - O(n) here n is the no of vertices  O(n+log*n) = O(n) (approx)
        Edge curr = input[i]; // because input is sorted so we will get min wt edge
        int src_par = find(parent,curr.src);  // TC - O(log*n)
        int dest_par = find(parent,curr.dest);
        if(src_par != dest_par){
            // include edge as this will not make cycle
            Union(parent,rank,curr.src,curr.dest);
            ans+= curr.wt;
            edgecount++;
        }
        i++; // does not matter you picked the last edge or not, we still need to go to next edge  
    }
    return ans;
}

int main(){
    cout<<"enter the no of nodes/vertices and no of edges: "<<endl;
    int n,e;
    cin>>n>>e;
    vector<Edge> v(e);
    for(int i =0; i<e; i++){
        cout<<"enter the source, destination and wt of edge: "<<endl;
        cin>>v[i].src>>v[i].dest>>v[i].wt;
    }
    cout<<kruskals(v,n,e);
    return 0;
}
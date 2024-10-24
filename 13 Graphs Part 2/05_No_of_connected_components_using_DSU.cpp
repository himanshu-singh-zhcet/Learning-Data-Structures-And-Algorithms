#include<bits/stdc++.h>
using namespace std;

class DSU{
    vector<int> parent;
    vector<int> rank;
    public:
    DSU(int n){
        parent.resize(n+1);
        rank.resize(n+1,1);
        for(int i =0;i<n;i++){
        parent[i]=i;
        }
    }
    int find(int a){
    return parent[a] = ((parent[a]==a)? a: find(parent[a]));
    }

    void Union(int a, int b){
    a = find(a);
    b = find(b);
    if(a==b){
        return ;
    }
    if(rank[a] >= rank[b]){
        rank[a]++;
        parent[b]= a;
    }
    else{
        rank[b]++;
        parent[a] = b;
    }
    }  
};

int count_components(int n, vector<pair<int,int>> edges){// here n is the no of vertices/node
    DSU dsu(n);
    for(auto edge: edges){
        dsu.Union(edge.first,edge.second);
    }
    unordered_set<int> root_set;
    for(int i =0;i<n;i++){
        root_set.insert(dsu.find(i));
    }
    return root_set.size();
}





int main() {
    int n = 5;  // Number of nodes
    vector<pair<int, int>> edges = {
        {0, 1},
        {1, 2},
        {3, 4}
    };

    cout << count_components(n, edges) << endl;  // Output: 3
    return 0;
}



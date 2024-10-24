#include<iostream>
#include<vector>
using namespace std;
int find(vector<int> &parent,int x){
    // this method returns which group/cluster belongs to
    return parent[x] = (parent[x]==x)? x : find(parent,parent[x]);
}
void Union(vector<int> &parent, vector<int> &rank, int a, int b){
        a = find(parent,a);
        b = find(parent,b);
        if(rank[a]>=rank[b]){
            rank[a]++;
            parent[b] = a;
        }
        else{
            rank[b]++;
            parent[a] = b;
        }
}
int main(){
    int n,m;
    cout<<"enter the no of elements"<<endl;
    cin>>n;
    cout<<"enter the no of quaries"<<endl;
    cin>>m;
    vector<int> parent(n+1);
    vector<int> rank(n+1,0);
    for(int i =0;i<n;i++){
        parent[i]=i;
    }
    while(m--){
        string str;
        cout<<"enter the string"<<endl;
        cin>>str;
        if(str=="union"){
            int x,y;
            cout<<"enter the two numbers for union"<<endl;
            cin>>x>>y;
            Union(parent,rank,x,y);   
        }
        else{
            int x;
            cout<<"enter a no to find"<<endl;
            cin>>x;
            cout<<find(parent,parent[x])<<endl;
        }
    }


return 0;
}



/*
   *********** Second apporch for Implementing DSU ***********
*/
class DisjointSet{
    vector<int> rank,parent,size;
    public:
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        size.resize(n+1);
        for(int i =0;i<=n;i++){
            parent[i] = i;
            size[i] =1;
        }
    }
    int find_parent(vector<int> &parent,int x){
    // this method returns which group/cluster belongs to
    return parent[x] = (parent[x]==x)? x : find_parent(parent,parent[x]);
    }
    void Union(vector<int> &parent, vector<int> &rank, int a, int b){
        a = find(parent,a);
        b = find(parent,b);
        if(rank[a]>=rank[b]){
            rank[a]++;
            parent[b] = a;
        }
        else{
            rank[b]++;
            parent[a] = b;
        }
    }
};

class DisjointSet{
    vector<int> rank,parent,size;
    public:
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        size.resize(n+1);
        for(int i =0;i<=n;i++){
            parent[i] = i;
            size[i] =1;
        }
    }
    int find(int node){
    if(node == parent[node]){
        return node;
    }
    return parent[node] == find(parent[node]);
    }
    void Union(int a, int b){
        a = find(a);
        b = find(b);
        if(rank[a]>=rank[b]){
            rank[a]++;
            parent[b] = a;
        }
        else{
            rank[b]++;
            parent[a] = b;
        }
    }
};
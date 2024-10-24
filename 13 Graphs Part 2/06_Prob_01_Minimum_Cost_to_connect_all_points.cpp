class Solution {
public:
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
        par[b]=a;
    }
    else{
        rank[b]++;
        par[a] = b;
    }
}

int kruskals(vector<vector<int>> &input, int n , int e){ // here n is the no of vertices and e is no of edges
    vector<int> parent(n+1);
    vector<int> rank(n+1,1);
    for(int i = 0;i<n;i++){
        parent[i]=i;
    }
    int edgecount = 0;  // tree banane ke liye exactly n-1 edges chahiye , here n is the no of edges
    int i = 0;
    long ans  = 0;
    while(edgecount<n-1 and i<input.size()){  // TC - O(n) here n is the no of vertices  O(n+log*n) = O(n) (approx)
        vector<int>  curr = input[i]; // because input is sorted so we will get min wt edge
        int src_par = find(parent,curr[0]);  // TC - O(log*n)
        int dest_par = find(parent,curr[1]);
        if(src_par != dest_par){
            // include edge as this will not make cycle
            Union(parent,rank,curr[0],curr[1]);
            ans+= curr[2];
            edgecount++;
        }
        i++; // does not matter you picked the last edge or not, we still need to go to next edge  
    }
    return ans;
}

    int minCostConnectPoints(vector<vector<int>>& points) {
        int v = points.size();   // v = no of /vertices/nodes/points
        vector<vector<int>> edges;
        for(int i = 0;i<v;i++){
            for(int j = i+1; j<v;j++){
                int x1 = points[i][0];
                int y1 = points[i][1];

                int x2 = points[j][0];
                int y2 = points[j][1];

                int d = abs(x1-x2)+abs(y1-y2);
                edges.push_back({i,j,d});
            }
        }
        auto cmp = [&](vector<int> &v1,vector<int> &v2){
            return v1[2]<v2[2];
        };
        sort(edges.begin(),edges.end(),cmp);

        return kruskals(edges,v,edges.size());
    }
};
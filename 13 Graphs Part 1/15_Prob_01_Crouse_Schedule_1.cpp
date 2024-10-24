class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<list<int>> graph(n);
        for(auto x:prerequisites ){
            vector<int> edge = x;
            int src = edge[1];
            int dest = edge[0];
            graph[src].push_back(dest);
        }
        
        // Kahn's algorithm
        vector<int> indegree(n,0);
        for(int i = 0;i<n;i++){
            for(auto neighbour: graph[i]){
                // i---> neighbour
                indegree[neighbour]++;
            }
        }

        queue<int> qu;
        unordered_set<int> vis;
        int count = 0;
        for(int i =0;i<n;i++){
            if(indegree[i]==0){
                qu.push(i);
                vis.insert(i);
                count++;
            }
        }
        while(not qu.empty()){
            int node = qu.front();
            qu.pop();
            for(auto neighbour: graph[node]){
                if(not vis.count(neighbour)){
                    indegree[neighbour]--;
                    if(indegree[neighbour]==0){
                        qu.push(neighbour);
                        vis.insert(neighbour);
                        count++;
                    }
                }
            }
        }
        if(count != n){
            return false;
        }
        return true;
    }
};
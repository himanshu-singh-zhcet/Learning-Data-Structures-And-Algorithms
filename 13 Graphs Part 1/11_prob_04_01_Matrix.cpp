class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int r = mat.size();
        int c = mat[0].size();
        vector<vector<int>> vis(r,vector<int>(c,0));
        vector<vector<int>> dist(r,vector<int>(c,0));
        queue<pair<pair<int,int>,int>> qu;
        for(int i =0;i<r;i++){
            for(int j = 0;j<c;j++){
                if(mat[i][j]==0){
                    qu.push({{i,j},0});
                    vis[i][j]=1; // marking visited 
                }
                else{
                    vis[i][j]=0;
                }
            }
        }
        vector<vector<int>> dir = {{-1,0},{1,0},{0,-1},{0,1}};
        while(!qu.empty()){
            int row = qu.front().first.first;
            int col = qu.front().first.second;
            int steps = qu.front().second;
            qu.pop();
            dist[row][col] = steps;
            for(int d = 0;d<4; d++){
                int nrow = row+dir[d][0];
                int ncol = col+dir[d][1];
                if( nrow<0 or ncol< 0 or nrow>=r or ncol>=c)continue;
                if(vis[nrow][ncol] == 1) continue;
                qu.push({{nrow,ncol},steps+1});
                vis[nrow][ncol] = 1;
            }
        }
        return dist;

    }
};
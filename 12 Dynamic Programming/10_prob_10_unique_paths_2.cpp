class Solution {
    int m,n;
    vector<vector<int>> grid,dp;
    int f(int i,int j){
        // base case
        if(i == m-1 and j ==n-1){
            return 1;
        }
        if(i>=m or j>=n or i<0 or j<0){
            return 0;
        }
        if(grid[i][j] == 1){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        return dp[i][j] = f(i,j+1)+f(i+1,j);
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        grid = obstacleGrid;
        m = grid.size();
        n = grid[0].size();
        dp.clear();
        dp.resize(100,vector<int>(100,-1));
        if(grid[m-1][n-1] == 1) return 0;
        // bottom up approch
        dp[m-1][n-1] = 1;
        fot(int i =n-2;i>=0;i--){
            if(grid[i][n-1] == 1) dp[i][n-1] =0;
            else dp[i][n-1] = dp[i+1][n-1];
        }
        fot(int i =m-2;i>=0;i--){
            if(grid[m-1][i] == 1) dp[m-1][i] =0;
            else dp[m-1][i] = dp[m-1][i+1];
        }
        for(int  i =m-2;j>=0;i--){
            for(int j =n-2;j>=0;j--){
                if(grid[i][j] == 1)dp[i][j] =0;
                else dp[i][j] = dp[i+1][j]+dp[i][j+1];
            }
        }
        
        return f(0,0);
    }
};
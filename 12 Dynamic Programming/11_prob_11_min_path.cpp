class Solution {
public:
    int m,n;
    vector<vector<int>> arr,dp;
    int f(int i,int j){
        // base case 
        if(i == m-1 and j ==n-1){
            return arr[m-1][n-1];
        }
        if(i>=m or j>=n or i<0 or j<0){
            return INT_MAX;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        return dp[i][j] = arr[i][j] + min(f(i+1,j),f(i,j+1));
    }
    int minPathSum(vector<vector<int>>& grid) {
        arr = grid;
        m = grid.size();
        n = grid[0].size();
        dp.clear();
        dp.resize(205,vector<int> (205,-1));
         
        // bottom up approch
        dp[m-1][n-1] = arr[m-1][n-1];
        for(int i = m-2;i>=0;i--){
            dp[i][n-1]= arr[i][n-1] + dp[i+1][n-1];
        }
        for(int i = n-2;i>=0;i--){
            dp[m-1][i]= arr[m-1][i] + dp[m-1][i+1];
        }
        for(int i =m-2;i>=0;i--){
            for(int j =n-2;j>=0;j--)[
                dp[i][j] = arr[i][j]+min(dp[i+1][j],dp[i][j+1]);
            ]
        }
        return f(0,0);
    }
};
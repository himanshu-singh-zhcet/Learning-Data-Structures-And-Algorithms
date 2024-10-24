class Solution {
public:
    vector<vector<int>> grid;
    vector<vector<int>> dp;

    //brute force apporch
    int f(int r,int c){
      if(r == grid.size()-1){
        return grid[r][c];
      }
      return grid[r][c]+min(f(r+1,c),f(r+1,c+1));
    }

    // memoization
    int ftb(int r,int c){
      if(r == grid.size()-1){
        return grid[r][c];
      }
      if(dp[r][c] != -1){
        return dp[r][c];
      }
      return dp[r][c] = grid[r][c]+min(ftb(r+1,c),ftb(r+1,c+1));
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        dp.clear();
        dp.resize(205,vector<int> (205,-1));
        grid = triangle;
        // return ftb(0,0);

        // bottom up approch
        int rows = grid.size();
        // base case 
        for(int i =0;i<grid[rows-1].size();i++){
          dp[rows-1][i] = grid[rows-1][i];
        }
        for(int r = rows-2;r>=0;r--){
          for(int c =0;c<grid[r].size();c++){
            dp[r][c] = grid[r][c]+min(dp[r+1][c],dp[r+1][c+1]);
          }
        }
        return dp[0][0];
    }
};
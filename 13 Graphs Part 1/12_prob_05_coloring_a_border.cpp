class Solution {
public:
    vector<vector<int>> dir = {{-1,0},{1,0},{0,-1},{0,1}};
    int rows;
    int cols;
    void dfs(vector<vector<int>>& grid, int row, int col, int clr){
        grid[row][col] = -clr;// for making visited
        int count = 0;
        for(int d = 0; d<4;d++){
        int nrow = row+dir[d][0];
        int ncol = col+dir[d][1];
        if(nrow<0 or ncol<0 or nrow >= rows or ncol>= cols or abs(grid[nrow][ncol]) != clr) continue;
        count++;
        if(grid[nrow][ncol]== clr){ // agr grid[nrow][nrow]ki value positive hai to visited nhi hai or dfs call krne ki jarurat hai 
            dfs(grid,nrow,ncol,clr);
        }
        }
        if(count == 4){
            grid[row][col] = clr;
        }

    } 
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        rows = grid.size();
        cols = grid[0].size();
        dfs(grid,row,col,grid[row][col]);
        for(int i = 0;i<rows;i++){
            for(int j = 0;j<cols;j++){
                if(grid[i][j]<0){
                    grid[i][j] = color;
                }
            }
        }
    return grid;
    }
};


// Second approch
class Solution {
public:
    vector<vector<int>> dir = {{-1,0},{1,0},{0,-1},{0,1}};
    int rows;
    int cols;

    void dfs(vector<vector<int>>& grid, vector<vector<int>>& visited, int row, int col, int clr, vector<pair<int, int>>& borderCells){
        visited[row][col] = 1; // mark as visited
        int count = 0;

        for(int d = 0; d < 4; d++){
            int nrow = row + dir[d][0];
            int ncol = col + dir[d][1];
            if(nrow >= 0 && ncol >= 0 && nrow < rows && ncol < cols && abs(grid[nrow][ncol]) == clr) {
                count++;
                if(!visited[nrow][ncol]){
                    dfs(grid, visited, nrow, ncol, clr, borderCells);
                }
            }
        }

        if(count < 4 || row == 0 || col == 0 || row == rows - 1 || col == cols - 1){
            borderCells.push_back({row, col});
        }
    }

    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        rows = grid.size();
        cols = grid[0].size();
        vector<vector<int>> visited(rows, vector<int>(cols, 0));
        vector<pair<int, int>> borderCells;
        int originalColor = grid[row][col];

        dfs(grid, visited, row, col, originalColor, borderCells);

        for(auto& cell : borderCells){
            grid[cell.first][cell.second] = color;
        }

        return grid;
    }
};

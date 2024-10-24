/* prob - 417 
There is an m x n rectangular island that borders both the Pacific Ocean and Atlantic Ocean. The Pacific Ocean touches the
island's left and top edges, and the Atlantic Ocean touches the island's right and bottom edges.

The island is partitioned into a grid of square cells. You are given an m x n integer matrix heights where heights[r][c] 
represents the height above sea level of the cell at coordinate (r, c).

The island receives a lot of rain, and the rain water can flow to neighboring cells directly north, south, east, and west 
if the neighboring cell's height is less than or equal to the current cell's height. Water can flow from any cell adjacent to 
an ocean into the ocean.

Return a 2D list of grid coordinates result where result[i] = [ri, ci] denotes that rain water can flow from cell (ri, ci) to 
both the Pacific and Atlantic oceans.

*/
class Solution {
public:
    vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}}; // i,j ->i+1,j->i-1,j->i,j+1->i,j-1
    int rows;
    int cols;
    vector<vector<int>> h;
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
       rows = heights.size();
       cols = heights[0].size();
       h = heights;
       queue<pair<int,int>> pacificbfs;
       queue<pair<int,int>> atlanticbfs;

       // step of multisource bfs 
       for(int i =0;i<rows;i++){
           pacificbfs.push({i,0});
           atlanticbfs.push({i,cols-1});
       }
       for(int j= 1 ;j<cols;j++){
            pacificbfs.push({0,j});
          
       }
       for(int j= 0;j<cols-1;j++){
           atlanticbfs.push({rows-1,j});
       }

       vector<vector<bool>> pacific = bfs(pacificbfs);
       vector<vector<bool>> atlantic = bfs(atlanticbfs);

       vector<vector<int>> result;
       for(int i =0;i<rows;i++){
           for(int j = 0;j<cols;j++){
               if(pacific[i][j] and atlantic[i][j]) result.push_back({i,j});
           }
       }
       return result;
    }
    vector<vector<bool>> bfs(queue<pair<int,int>> &qu){
        vector<vector<bool>> visited(rows, vector<bool> (cols,false));
        while(not qu.empty()){
            auto cell = qu.front();
            qu.pop();
            int i = cell.first;
            int j = cell.second;
            visited[i][j] = true;
            for(int d=0;d<4;d++){
                int newrow = i+dir[d][0];
                int newcol = j+dir[d][1];
                if(newrow<0 or newcol<0 or newrow>=rows or newcol>= cols)continue; // you exicted the grid
                if(visited[newrow][newcol]) continue;
                if(h[newrow][newcol]<h[i][j]) continue; // h[newrow][newcol]->neighbours height,h[i][j]-> current cell height
                qu.push({newrow,newcol});

            }
        }
        return visited;
    }
};
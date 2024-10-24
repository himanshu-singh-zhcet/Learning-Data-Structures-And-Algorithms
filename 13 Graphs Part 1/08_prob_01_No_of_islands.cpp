class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int cc=0; // stores the no of connected components
        for(int r=0;r<rows;r++){
            for(int c=0; c<cols;c++){ 
                if(grid[r][c]=='0'){
                    continue; // it is a water body 
                }
                cc++; // new unvisited piece fount that is new connencted component
                grid[r][c]='0'; // mark it visited
                queue<pair<int,int>> qu;
                qu.push({r,c});  // store the source node
                while(! qu.empty()){
                    auto curr = qu.front();
                    qu.pop();
                    // go to all unvisited neighbous of current node 
                    int currrow = curr.first;
                    int currcol = curr.second;
                    // checkup
                    if(currrow-1>=0 and grid[currrow-1][currcol] == '1'){
                        qu.push({currrow-1,currcol});
                        grid[currrow-1][currcol] = '0';
                    }
                    // checkdown
                    if(currrow+1<rows and grid[currrow+1][currcol] == '1'){
                        qu.push({currrow+1,currcol});
                        grid[currrow+1][currcol] = '0';
                    }
                    // checkleft
                    if(currcol-1>=0 and grid[currrow][currcol-1] == '1'){
                        qu.push({currrow,currcol-1});
                        grid[currrow][currcol-1] = '0';
                    }
                    // check right
                    if(currcol+1<cols and grid[currrow][currcol+1] == '1'){
                        qu.push({currrow,currcol+1});
                        grid[currrow][currcol+1] = '0';
                    }
                    
                }
            }
            
        }
        return cc;
    }
};
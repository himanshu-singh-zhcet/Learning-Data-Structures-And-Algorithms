class Solution {
public:
    bool canweplace(vector<vector<char>> &board,int row,int col, char num){
    // checking in the row
    for(int j =0;j<=9;j++){
        if(board[row][j]== num) return false;
    }
    
    // checking in the col
    for(int j =0;j<=9;j++){
        if(board[j][col]== num) return false;
    }

    // checking in the subgrid 
    int r = (row/3)*3;
    int c = (col/3)*3;
    for(int i =r;i<(r+3);i++){
        for(int j=c;j<(c+3);j++){
            if(board[i][j]==num) return false;
        }
    }
    return true;
    }

    bool sudoko(vector<vector<char>> &board,int row,int col){
        // base case 
        if(col ==9){
            return sudoko(board,row+1,0);
        }
        if(row == 9){
            return true;
        }
        if(board[row][col]=='.'){
            for(int num =1;num<=9;num++){
                if(canweplace(board,row,col,'0'+num)){
                    board[row][col] = '0'+num;
                    bool res = sudoko(board,row,col+1);
                    if(res) return true;
                    board[row][col]= '.';
                }
            }
            return false;
        }
        else{
            return sudoko(board,row,col+1);
        }
    }
    void solveSudoku(vector<vector<char>>& board) {
        sudoko(board,0,0);   
};
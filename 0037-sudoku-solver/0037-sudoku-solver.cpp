class Solution {
public:
    bool isSafe(int row,int col,char num,vector<vector<char>>& board){
        for(int i=0;i<9;i++){
            if(board[i][col] == num) return false;
            
            if(board[row][i]== num) return false;
                          
            if(board[3*(row/3) + i/3][3*(col/3) + i%3] == num)
                          return false;
        }
        return true;
    }
    
    bool solve(vector<vector<char>>& board){
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board.size();j++){
                if(board[i][j] == '.'){
                    for(int k=1;k<10;k++){
                        if(isSafe(i,j,k+'0',board)){
                            board[i][j] = k+'0';
                            if(solve(board) == true)
                                return true;
                            else
                                board[i][j] = '.';
                        }
                    }
                return false;
                }
            }
        }
    return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};
class Solution {
public:
    bool isSafe(int row,int col,vector<string>& board,int n){
        for(int j=col;j>=0;j--){
            if(board[row][j] == 'Q') return false;
        }
        
        
        for(int i=row,j=col;i>=0 && j>=0;i--,j--){
            if(board[i][j] == 'Q') return false;
        }
        
        
        for(int i=row,j=col;i<n && j>=0;i++,j--){
            if(board[i][j] == 'Q') return false;
        }
    return true;
    }
    void solve(int col,int n,vector<vector<string>> &ans,vector<string> &board){
        
        if(col == n){
            ans.push_back(board);
            return;
        }
        
        for(int row = 0;row<n;row++){
            if(isSafe(row,col,board,n)){
                board[row][col] = 'Q';
                solve(col+1,n,ans,board);
                board[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        string str(n,'.');
        vector<string> board(n,str);
        
        solve(0,n,ans,board);
        
    return ans;
    }
};
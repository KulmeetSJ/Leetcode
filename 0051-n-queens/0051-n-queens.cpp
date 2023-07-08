class Solution {
public:
    bool isSafe(int row,int col,vector<string> &board,int n){
        //Checking left for Queen
        for(int j=col;j>=0;j--){
            if(board[row][j] == 'Q')  return false;
        }
        
        //Left Upper diagonal
        for(int i=row,j=col;i>=0 && j>=0;i--,j--){
            if(board[i][j] == 'Q') return false;
        }
        
        //Left Lower Diagonal
        for(int i=row,j=col;i<n && j>=0;i++,j--){
            if(board[i][j] == 'Q') return false;
        }
return true;
}
    
    void solve(int col,vector<string> &board,vector<vector<string>> &ans,int n){
        if(col == n){
            ans.push_back(board);
            return;
        }
        
        for(int row=0;row<n;row++){
            if(isSafe(row,col,board,n)){
                board[row][col] = 'Q';
                solve(col+1,board,ans,n);
                board[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        string str(n,'.');
        vector<string> board(n,str);
        vector<vector<string>> ans;
        
        solve(0,board,ans,n);
    return ans;
    }
};
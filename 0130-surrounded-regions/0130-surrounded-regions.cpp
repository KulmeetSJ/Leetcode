class Solution {
public:
    void dfs(int row,int col,vector<vector<char>>& board,vector<vector<int>> &vis,vector<vector<int>> directions,int m,int n){
        vis[row][col] = 1;
        
        for(auto i:directions){
            int nrow = row+ i[0];
            int ncol = col+ i[1];
            if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && board[nrow][ncol] == 'O' && !vis[nrow][ncol]){
                dfs(nrow,ncol,board,vis,directions,m,n);
            }
        }
        
        
    }
    void solve(vector<vector<char>>& board) {
        int m = board.size(),n=board[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        vector<vector<int>> directions = {{-1,0},{0,1},{1,0},{0,-1}};
        
        //First we will traverse all the boundaries 
        //Left boundary
        for(int i=0;i<m;i++){
            if(board[i][0] == 'O' && !vis[i][0]) dfs(i,0,board,vis,directions,m,n);
        }
        //Right boundary
        for(int i=0;i<m;i++){
            if(board[i][n-1] == 'O' && !vis[i][n-1]) dfs(i,n-1,board,vis,directions,m,n);
        }
        //Upper boundary
        for(int i=0;i<n;i++){
            if(board[0][i] == 'O' && !vis[0][i]) dfs(0,i,board,vis,directions,m,n);
        }
        //Lower boundary
        for(int i=0;i<n;i++){
            if(board[m-1][i] == 'O' && !vis[m-1][i]) dfs(m-1,i,board,vis,directions,m,n);
        }
        
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j] =='O' && vis[i][j] == 0 ){
                    board[i][j] = 'X';
                }
            }
        }
        
        
        
        
    }
};
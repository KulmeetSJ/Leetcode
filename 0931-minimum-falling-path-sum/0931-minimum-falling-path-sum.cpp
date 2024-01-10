class Solution {
public:
    int solve(int row,int col,vector<vector<int>>& matrix,int n,int m){
        if( col < 0 || col >= m){
            return 1e9;
        }
        if(row == 0){
            return matrix[row][col];
        }
        
        
        //Upr wale ko lo
        int s  = matrix[row][col] + solve(row-1,col,matrix,n,m);
        //Left uppr ko lo
        int ld = matrix[row][col] + solve(row-1,col-1,matrix,n,m);
        //Right uppr ko lo
        int rd = matrix[row][col] + solve(row-1,col+1,matrix,n,m);
        
        
        return min(s,min(ld,rd));
    }
    
    int solveMem(int row,int col,vector<vector<int>>& matrix,int n,int m,vector<vector<int>>& dp){
        if(col<0 || col >=m){
            return 1e9;
        }
        if(row == 0 ){
            return matrix[row][col];
        }
        
        if(dp[row][col] != -1) return dp[row][col];
        
        int u = matrix[row][col] + solveMem(row-1,col,matrix,n,m,dp);
        int ld = matrix[row][col] + solveMem(row-1,col-1,matrix,n,m,dp);
        int rd = matrix[row][col] + solveMem(row-1,col+1,matrix,n,m,dp);
        
        return dp[row][col] = min(u,min(ld,rd));
    }
    
    int tabu(vector<vector<int>>& matrix,int n,int m){
        
        vector<vector<int>> dp(n,vector<int>(m,0));
        
        for(int j=0;j<m;j++) dp[0][j] = matrix[0][j];
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                int u = matrix[i][j] + dp[i-1][j];
                int ld = matrix[i][j] , rd = matrix[i][j];
                if(j-1 >=0) ld += dp[i-1][j-1];
                else ld += 1e9;
                if(j+1 < m) rd += dp[i-1][j+1];
                else rd += 1e9;
                dp[i][j] = min(u,min(ld,rd));
            }
        }
        int mini = 1e9;
        
        for(int j=0;j<m;j++){
            mini = min(mini,dp[n-1][j]);
        }
        
        return mini;
    }
    
    int spaceOpt(vector<vector<int>>& matrix,int n,int m){
        vector<int> prev(m,0) , curr(m,0);
        
        for(int j=0;j<m;j++) prev[j] = matrix[0][j];
        
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                int u = matrix[i][j] + prev[j];
                int ld = matrix[i][j] , rd = matrix[i][j];
                if(j-1 >=0) ld += prev[j-1];
                else ld += 1e9;
                if(j+1 < m) rd += prev[j+1];
                else rd += 1e9;
                curr[j] = min(u,min(ld,rd));
            }
            prev = curr;
        }
        
        int mini = 1e9;
        for(int j=0;j<m;j++){
            mini = min(mini,prev[j]);
        }
        return mini;
    }
    
    
    
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        
//         int mini = 1e9;
//         vector<vector<int>> dp(n,vector<int>(m,-1));
//         for(int j=0;j<m;j++){
//         mini = min(solveMem(n-1,j,matrix,n,m,dp),mini);
            
//         }
        //return mini;
        
        //return tabu(matrix,n,m);
        return spaceOpt(matrix,n,m);
    }
};
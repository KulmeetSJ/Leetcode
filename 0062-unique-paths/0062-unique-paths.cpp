class Solution {
public:
    //Recursion
    int solve(int i,int j, int m,int n)
    {
        if(i >= m || j>= n)
        {   
            return 0;
        }
        if(i == m-1 && j== n-1)
            return 1;
        else 
            return solve(i+1,j,m,n) + solve(i,j+1,m,n);        
    }
    
    //Recursion + Memoization
    int solveMem(int i,int j,int m,int n,vector<vector<int>> &dp)
    {
        if(i >=m || j>=n)
        {
            return 0;
        }
        if(i == m-1 && j == n-1)
            return 1;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        return dp[i][j] = solveMem(i+1,j,m,n,dp)+ solveMem(i,j+1,m,n,dp);
        
    }
    
    
    
    int uniquePaths(int m, int n) {
        //Recursion
        //return solve(0,0,m,n);
        
        vector<vector<int>>dp(m,vector<int>(n,-1));
        
        return solveMem(0,0,m,n,dp);
    }
};
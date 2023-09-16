class Solution {
public:
    int memo(int n,vector<int> &dp){
        if(n <= 1) return 1;
        
        if(dp[n] != -1) return dp[n];
        
        
        return dp[n] = climbStairs(n-1) + climbStairs(n-2);
    }
    int tabu(int n){
        vector<int> dp(n+1,-1);
        dp[0] = dp[1] = 1;
        
        for(int i=2;i<=n;i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
    return dp[n];
    }
    int climbStairs(int n) {
        
        return tabu(n);
     
    }
};
class Solution {
public:
    int lcs(string &s,string &t,int i,int j)
    {
        if(i==s.length() || j==t.length())
            return 0;
        
        int ans = 0;
        
        if(s[i] == t[j])
        {
            ans = 1 + lcs(s,t,i+1,j+1);
        }
        else
            ans = max(lcs(s,t,i+1,j) , lcs(s,t,i,j+1));
         
    return ans;
    }
    
    int lcsMem(string &s,string &t,int i,int j,vector<vector<int>>& dp)
    {
        if(i==s.length() || j==t.length())
            return 0;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int ans = 0;
        
        if(s[i] == t[j])
        {
            ans = 1 + lcs(s,t,i+1,j+1);
        }
        else
            ans = max(lcs(s,t,i+1,j) , lcs(s,t,i,j+1));
         
    return dp[i][j]=ans;  
    }
    
    int lcsTab(string &s,string &t)
    {
        int n = s.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        for(int i =n-1;i>=0;i--)
        {
            for(int j=n-1;j>=0;j--)
            {
                int ans = 0;
        
                if(s[i] == t[j])
                {
                   ans = 1 + dp[i+1][j+1];
                }
                else
                   ans = max(dp[i+1][j] , dp[i][j+1]);
         
                dp[i][j]=ans;  
            }
        }
    return dp[0][0];
    }
    
    int longestPalindromeSubseq(string s) {
        string t = s;
        reverse(t.begin(),t.end());
        
        //Recursive
        //return lcs(s,t,0,0);
        
        //Recursive + Mem
        
        //vector<vector<int>> dp(s.size(),vector<int>(2,-1));
        
        //return lcsMem(s,t,0,0,dp);
        
        return lcsTab(s,t);
    }
};
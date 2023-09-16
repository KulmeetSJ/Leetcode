//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
#define MOD 1000000007
class Solution {
  public:
    int fibo_memo(int n,vector<int>&dp){
        if(n == 0 || n == 1) return n;
        if(dp[n] != -1) return dp[n];
        
        return dp[n] = (fibo_memo(n-1,dp) % MOD + fibo_memo(n-2,dp) % MOD )%MOD;
    }
    
    int fibo_tab(int n){
        vector<int> dp(n+1,-1);
        dp[0] = 0 , dp[1]  = 1;
        for(int i=2;i<=n;i++){
            dp[i] =( dp[i-1]%MOD + dp[i-2]%MOD )%MOD;
        }
        return dp[n];
    }
    
    int nthFibonacci(int n){
        vector<int> dp(n+1,-1);
        return fibo_memo(n,dp)%MOD;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.nthFibonacci(n) << endl;
    }
    return 0;
}

// } Driver Code Ends
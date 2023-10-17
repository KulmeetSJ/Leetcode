class Solution {
public:
    int rec_mem(int ind, vector<int> nums,vector<int>& dp){
        if(ind == 0) return nums[ind];
        else if(ind < 0) return 0;
        
        if(dp[ind] != -1) return dp[ind];
        
        int pick = nums[ind] + rec_mem(ind-2,nums,dp);
        int notPick = rec_mem(ind-1,nums,dp);
        
        return dp[ind] = max(pick,notPick);
    }
    int tabu(vector<int> nums){
        int n = nums.size();
        vector<int> dp(n,-1);
        dp[0] = nums[0];
        
        
        for(int ind = 1;ind<n;ind++){
            
            int pick = nums[ind];
            if(ind > 1 ){
                pick +=  dp[ind-2];
            }
            
            int notPick = dp[ind-1];
            dp[ind] = max(pick,notPick);
        }
    return dp[n-1];
    }
    int rob(vector<int>& nums) {
        //vector<int> dp(nums.size(),-1);
        //return rec_mem(nums.size()-1,nums,dp);
        return tabu(nums);
    }
};
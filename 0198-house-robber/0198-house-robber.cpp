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
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        return rec_mem(nums.size()-1,nums,dp);
    }
};
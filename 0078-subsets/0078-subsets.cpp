class Solution {
public:
    
    void solve(int ind,vector<int>& nums,vector<int> &ds,vector<vector<int>>& ans){
        if(ind == nums.size()){
            ans.push_back(ds);
            return;
        }
        solve(ind+1,nums,ds,ans);
        ds.push_back(nums[ind]);
        solve(ind+1,nums,ds,ans);
        ds.pop_back();
    }
   
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        
        solve(0,nums,ds,ans);
    return ans;
    }
};
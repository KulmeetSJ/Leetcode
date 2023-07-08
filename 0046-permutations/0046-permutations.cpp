class Solution {
public:
    void solve(vector<int> &mp,vector<int> &nums,vector<int> &ds,vector<vector<int>> &ans){
        if(ds.size() == nums.size()){
            ans.push_back(ds);
            return;
        }
        
        for(int i=0;i<nums.size();i++){
            if(!mp[i]){
            mp[i] = 1;
            ds.push_back(nums[i]);
            solve(mp,nums,ds,ans); 
            ds.pop_back();
            mp[i] = 0;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> ds;
        vector<vector<int>> ans;
        
        vector<int> mp(nums.size(),0);
        
        solve(mp,nums,ds,ans);
        
        return ans;
    }
};
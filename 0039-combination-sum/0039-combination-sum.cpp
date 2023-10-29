class Solution {
public:
    void combinations(int ind,vector<int>& candidates,int target,int sum,vector<vector<int>> &ans,vector<int> &ds){
        
        if(ind >= candidates.size()){
            if(target == sum){
                ans.push_back(ds);
            }
            return;
        }
        //Take
        if(candidates[ind] + sum <= target){
        ds.push_back(candidates[ind]);
        sum += candidates[ind];
        combinations(ind,candidates, target,sum,ans,ds);
        ds.pop_back();
        sum -= candidates[ind];
        }
        
        //Not Take
        combinations(ind+1,candidates,target,sum,ans,ds);        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        
        combinations(0,candidates,target,0,ans,ds);
        
        return ans;
    }
};
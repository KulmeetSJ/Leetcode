class Solution {
public:
    void combinations(int ind,vector<int> &candidates,int target,
                      vector<vector<int>> &ans,vector<int> &ds){
        if(target == 0){
            ans.push_back(ds);return;
        }
        
        
        for(int i=ind;i<candidates.size();i++){
            if(i>ind && candidates[i] == candidates[i-1]) continue;
            if(candidates[i] > target) break;
            
            ds.push_back(candidates[i]);
            combinations(i+1,candidates,target-candidates[i],ans,ds);
            ds.pop_back();
        }
        
                
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int>ds;
        sort(candidates.begin(),candidates.end());
        int n = candidates.size();
        combinations(0,candidates,target,ans,ds);
        
     return ans;
    }
};
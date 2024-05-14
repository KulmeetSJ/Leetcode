
#define vi vector<int>
#define vvi vector<vector<int>>

class Solution {
public:
    void helper(int idx, vi &candidates, int n, int target, vvi &ans, vi &ds ) {
	if (idx >= n) {
		if (target == 0) {
			ans.push_back(ds);
		}
		return;
	}

	if (target - candidates[idx] >= 0) {
		ds.push_back(candidates[idx]);
		target -= candidates[idx];
		helper(idx, candidates, n, target, ans, ds);
		ds.pop_back();
		target += candidates[idx];
	}

	helper(idx + 1, candidates, n, target, ans, ds);
}
    
    vvi combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();

	vvi ans;
	vi ds;

	helper(0, candidates, n, target, ans, ds);

	return ans;
    }
};
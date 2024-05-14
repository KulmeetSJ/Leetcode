#define vi vector<int>
#define vvi vector<vector<int>>
#define pb push_back
#define pob pop_back

class Solution {
public:
    void helper(int idx, vi &candidates, int n, int target, vvi &ans, vi &ds ) {
	if (target == 0) {
		ans.pb(ds);
		return;
	}


	for (int i = idx; i < n; i++) {
		if (i > idx && candidates[i] == candidates[i - 1]) continue;

		if (candidates[i] > target) break;

		ds.pb(candidates[i]);
		helper(i + 1, candidates, n, target - candidates[i], ans, ds);
		ds.pob();
	}
}
    
    
    vvi combinationSum2(vi& candidates, int target) {
        int n = candidates.size();

	vvi ans;
	vi ds;

	sort(candidates.begin(), candidates.end());

	helper(0, candidates, n, target, ans, ds);

	return ans;
    }
};
  #define vvs vector<vector<string>>
#define vs vector<string>

class Solution {
public:
  

bool isPalin(string str, int left, int right) {

	for (int i = left; i <= right; i++) {
		if (str[i] != str[right - i + left]) {
			return false;
		}
	}
	return true;
}

void helper(int idx, int n, string str, vvs &ans, vs &ds) {
	if (idx == n) {
		ans.push_back(ds);
		return;
	}

	string temp = "";

	for (int i = idx; i < n; i++) {
		temp += str[i];

		if (isPalin(str, idx, i)) {
			ds.push_back(temp);
			helper(i + 1, n, str, ans, ds);
			ds.pop_back();
		}
	}
}

vvs partition(string str) {
	int n = str.length();

	vvs ans;
	vs ds;

	helper(0, n, str, ans, ds);

	return ans;
}

};
typedef long long ll;
#define vc vector<char>
#define mpic map<ll,vc>
#define vs vector<string>
#define pb push_back

class Solution {
public:
    void helper(int idx, string &str, mpic &mp, vs &ans, string curr) {
	if (idx == str.length()) {
		ans.pb(curr);
		return;
	}

	for (auto it : mp[str[idx] - '0']) {
		helper(idx + 1, str, mp, ans, curr + it);
	}
}

    vs letterCombinations(string digits) {
        
        vs ans;
        if(digits.length() == 0){
            return ans;
        }

	mpic mp;

	mp[2] = {'a', 'b', 'c'};
	mp[3] = {'d', 'e', 'f'};
	mp[4] = {'g', 'h', 'i'};
	mp[5] = {'j', 'k', 'l'};
	mp[6] = {'m', 'n', 'o'};
	mp[7] = {'p', 'q', 'r', 's'};
	mp[8] = {'t', 'u', 'v'};
	mp[9] = {'w', 'x', 'y', 'z'};

	helper(0, digits, mp, ans, "");


	return ans;
    }
};
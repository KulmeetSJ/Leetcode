class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> mp;
        unordered_map<char,bool> mp2;
        int i=0;
        while(i<s.length()){
            if(mp.find(s[i]) == mp.end()){
                if(mp2[t[i]] == true) return false;
                mp[s[i]] = t[i];
                mp2[t[i]] = true;
            }
            else{
                char ch = mp[s[i]];
                if(ch != t[i]) return false;
            }
        i++;
        }
    return true;
    }
};
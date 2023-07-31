class Solution {
public:
    int beautySum(string s) {
        int ans = 0;
        
        for(int i=0;i<s.length();i++){
            map<char,int> mp;
            multiset<int> st;
            for(int j=i;j<s.length();j++){
                if(mp.find(s[j]) != mp.end()){
                    st.erase(st.find(mp[s[j]]));
                }
                mp[s[j]]++;
                st.insert(mp[s[j]]);
                
                ans += (*st.rbegin() - *st.begin());
            }
        }
    return ans;
    }
};
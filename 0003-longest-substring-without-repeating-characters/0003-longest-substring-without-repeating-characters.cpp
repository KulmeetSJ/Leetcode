class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int> mp;
        
        if(s.empty()) return 0;
        
        int left = 0 , right = 0;
        int maxLen = INT_MIN;
        while(right < s.size())
        {   
            char ch = s[right];
            
            //Mil gya
            if(!mp.empty() && mp.find(ch) != mp.end())
              left = max(mp[ch] + 1,left);
            
            mp[ch] = right;   
            int len = right-left+1;
            maxLen = max(maxLen,len);
            right++;  
        }
    return maxLen;
    }
};
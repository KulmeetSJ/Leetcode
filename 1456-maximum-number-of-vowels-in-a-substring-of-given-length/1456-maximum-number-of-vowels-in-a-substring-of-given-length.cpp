class Solution {
public:
    bool checkVowel(char ch)
    {
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
            return true;
        
    return false;
    }
    
    int maxVowels(string s, int k) {
        int maxi = INT_MIN;
        int curr = 0;
        int n = s.length();
        
        for(int i=0;i<n;i++)
        {
            curr += (int)checkVowel(s[i]);
            if(i>=k)
                curr -= (int)checkVowel(s[i-k]);
            
            maxi = max(curr,maxi);
        }
    return maxi;
    }
};
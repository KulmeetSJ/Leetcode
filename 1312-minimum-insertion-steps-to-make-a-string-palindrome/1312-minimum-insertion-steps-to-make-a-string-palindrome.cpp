class Solution {
public:
    int longestPalinSubsequence(string &s)
    {
        int n = s.size();
        vector<int> curr(n),prev(n);
        
        for(int start = n-1;start>=0;start--)
        {
            curr[start] = 1;
            for(int end = start+1;end<n;end++)
            {
                if(s[start] == s[end])
                {
                    curr[end] = prev[end-1] + 2;
                }
                else
                {
                    curr[end] = max(prev[end],curr[end-1]);
                }
            }
            prev = curr;
        }
    return curr[n-1];
    }
    int minInsertions(string s) {
        return s.length() - longestPalinSubsequence(s);
    }
};
class Solution {
public:
    void solve(int left,int right,string &s,int &longest,string &res,int n){
        while(left>=0 && right<n && s[left] == s[right]){
                if(right-left+1 > longest){
                    longest = right-left+1;
                    res = s.substr(left,right-left+1);
                }
                left--; right++;
            }
    }
    string longestPalindrome(string s) {
        string res = "";
        int longest = 0;
        int n = s.length();
        
        for(int i=0;i<n;i++){
            //Odd length palindromes
            solve(i,i,s,longest,res,n);
            //Even length palindromes 
            solve(i,i+1,s,longest,res,n);
        }
    return res;
    }
};
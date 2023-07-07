class Solution {
public:
    bool isPalindrome(string s,int start,int end){
        while(start<=end){
            if(s[start++] != s[end--]){
                return false;
            }
        }
    return true;
    }
    
    void solve(int index,vector<string> &ds,string &s,vector<vector<string>> &ans){
        if(index == s.length()){
            ans.push_back(ds);
            return;
        }
        
        for(int i=index;i<s.length();i++){
            if(isPalindrome(s,index,i)){
                ds.push_back(s.substr(index,i-index+1));
                solve(i+1,ds,s,ans);
                ds.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> ds;
        
        solve(0,ds,s,ans);
        
        return ans;
    }
};
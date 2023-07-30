class Solution {
public:
    string compare(string &s1,string &s2){
        int len = min(s1.length(),s2.length());
        string common = "";
        int i=0;
        while(i<len){
            if(s1[i] != s2[i]) break;
            else{
                common += s1[i];
            }
            i++;
        }
    return common;
    }
    string longestCommonPrefix(vector<string>& strs) {
        string ans = strs[0];
        
        for(int i=1;i<strs.size();i++){
            ans = compare(ans,strs[i]);   
        }
    return ans;
    }
};
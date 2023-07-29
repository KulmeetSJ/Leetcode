class Solution {
public:
    bool isPalindrome(string s) {
        
        string st ="";
        for(int i=0;i<s.size();i++){
           if(s[i] >= 'a' && s[i]<='z'  || s[i] >='0' && s[i] <= '9'){
               st += s[i];
           }
           else if(s[i]>='A' && s[i] <= 'Z'){
               char ch = s[i]-'A'+'a';
               st += ch;
           }
        }
        
        int i=0,j=st.length()-1;
        
        while(i<j){
            if(st[i]!=st[j]) return false;
            i++ , j--;
        }
    return true;
    }
};
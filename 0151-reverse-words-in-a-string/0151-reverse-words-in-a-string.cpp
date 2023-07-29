class Solution {
public:
    string reverseWords(string s) {
        int len = s.size();
        int i = len-1;
        s+=" ";
        
        while(true){
            while(i>=0 && s[i] == ' ')i--;
            if(i<0)break;
            int j = i-1;
            while(j>=0 && s[j] != ' ')j--;
            s+= s.substr(j+1,i-j)+ " ";
            i=j-1;            
        }
        s = s.substr(len+1,s.size()-(len+2));
        return s;
    }
};
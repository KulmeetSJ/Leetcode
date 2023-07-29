class Solution {
public:
    int min(int a,int b){
        return a<b?a:b;
    }
    string reverseStr(string s, int k) {
       for(int start = 0; start<s.length();start += 2*k){
           int i = start;
           int j = min((start+k-1),(s.length()-1));
           while(i<j){
               swap(s[i++],s[j--]);
           }
       }
    return s;
    }
};
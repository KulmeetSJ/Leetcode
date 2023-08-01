class Solution {
public:
    void getZarr(string str,int len,vector<int>&Z){
        int L=0,R=0;
        int k;
        
        for(int i=1;i<len;i++){
            if(i>R){
                L = R = i;
                while(R<len && str[R-L] == str[R]) R++;
                Z[i] = R-L;
                R--;
            }
            else{
                k = i-L;
                if(Z[k] < R-i+1) Z[i]=Z[k];
                else{
                    L=i;
                    while(R<len && str[R-L] == str[R]) R++;
                    Z[i] = R-L;
                    R--;
                }
            }
        }
    }
    int strStr(string haystack, string needle) {
        string concat = needle + "$" + haystack;
        int len = concat.length();
        vector<int> Z(len);
        
        getZarr(concat,len,Z);
        
        for(int i=0;i<len;i++){
            if(Z[i] == needle.length()) return i-needle.length()-1;
        }
    return -1;
    }
};
class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.length();
        string ans = "";
        for(int j=n-1;j>=0;){
            if(num[j] %2 == 0) j--;
            else{
                while(j>=0){
                    ans+=num[j];
                    j--;
                }
            }
        }
        reverse(ans.begin(),ans.end());
    return ans;
    }
};
class Solution {
public:
    string build(string num){
        int freq = 1;
        char curr = num[0];
        string res = "";
        
        for(int i=1;i<num.length();i++){
            if(curr == num[i]) freq++;
            else{
                char fr = '0'+freq;
                res.push_back(fr);
                res.push_back(curr);
                
                curr = num[i];
                freq = 1;
            }
        }
         char fr = '0'+freq;
         res.push_back(fr);
         res.push_back(curr);
             
             
    return res;
    }
    string countAndSay(int n) {
        string initial = "1";
        
        for(int i=0;i<n-1;i++){
            initial = build(initial);
        }
    return initial;
    }
};
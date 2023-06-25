class Solution {
public:
    int maxPower(string s) {
        int power = 0;
        int cnt = 0;
        bool first = true;
        for(int i=1;i<s.size();i++){
            if(s[i] != s[i-1]){
                cnt = 0;
                first = true;
            }
            else{
                if(first){
                    cnt+=2;
                    first = false;
                }
                else{
                    cnt++;
                }
            }
            power = max(power,cnt);
        }
    if(power == 0)
        return 1;
    else
        return power;
    }
};
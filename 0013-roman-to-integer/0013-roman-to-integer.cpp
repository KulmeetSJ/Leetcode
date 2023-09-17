class Solution {
public:
    int romanToInt(string s) {
        map<char,int> mp;
        mp['I'] = 1 , mp['V'] = 5 , mp['X'] = 10 , mp['L'] =50 , mp['C'] = 100 , mp['D'] = 500 , mp['M'] = 1000;
        
        int ans = 0;
        for(int i=0;i<s.length();i++){
            if(i>0 && mp[s[i-1]] < mp[s[i]]){
                int temp = mp[s[i]] - mp[s[i-1]];
                ans += temp;
            }
            else if(i<s.length()-1 && mp[s[i+1]] > mp[s[i]]){
                //i++;
                continue;
            }
            else{
                ans += mp[s[i]];
            }
        }
    return ans;
    }
};

/*

LVIII

i = 0 to s.length()-1  , ans = 0;

s[0] = 'L' -> 50 ..ans += 50; // 50
s[1] = 'V' -> 5 ..ans += 5 // 55
.. // 58


CM -> 900? 

MCMXCIV 


s[0] = 'M' -> 1000 // ans = 1000
s[1] = 'C' -> 100 // ans = 1100  // if(s[i+1] > s[i]) continue;
s[2] = 'M' -> 1000 // if[s[i-1] < s[i]] .. s[i] = s[i]-s[i-1]
C->100 ..M-> 1000 ... s[2] .. 1000-100 = 900

ans = 1900

s[3] = 'X' -> 10 .. if(s[i+1] > s[i]) continue; // TRue.. so we will not add X's value and proceed

s[4] = 'C' -> 100 ..  if[s[i-1] < s[i]]// True .. s[i] = s[i]-s[i-1] // 100-10 = 90

ans = 1900+90 = 1990

s[5] = 'I'

s[6] = 'V' -> 5 ..5-1 =4 

1994



MC 

ans = 1100

*/
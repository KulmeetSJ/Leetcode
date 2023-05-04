class Solution {
public:
    string modifyString(string s) {
        int n = s.length();
        
        if(n==1)
        {
            s[0] = 'a';
            return s;
        }
        
        for(int i=0;i<n;i++)
        {
            if(s[i] == '?')
            {   
                for(char ch ='a';ch<='z';ch++)
                {
                if(i == 0)
                {
                   if(s[i+1] != ch)
                   {
                       s[i] = ch;
                       break;
                   }
                }
                else if(i == n-1)
                {
                    if(s[i-1] != ch)
                   {
                       s[i] = ch;
                       break;
                   }                    
                }
                else
                {
                    if (s[i - 1] != ch && s[i + 1] != ch)
                        {
                            s[i] = ch;
                            break;
                        }
                }
                }
            }
            
        }
    return s;
    }
};
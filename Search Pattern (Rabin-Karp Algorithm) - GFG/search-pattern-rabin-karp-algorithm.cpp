//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


#define d 256
#define q INT_MAX
class Solution
{
    public:
        vector <int> search(string pat, string txt)
        {   
            vector<int> idx;
            int n = txt.length();
            int m = pat.length();
            int i,j;
            int p =0, t=0;
            int h=1;
            //Calculate h
            for(i=0;i<m-1;i++){
                h = (h*d)%q;
            }
            //Calulate hash values of both
            
            for(i=0;i<m;i++){
                p = (d*p + pat[i])%q;
                t = (d*t + txt[i])%q;
            }
            
            for(i=0;i<=n-m;i++){
                if(p == t){
                    for(j=0;j<m;j++){
                        if(pat[j] != txt[i+j]) break;
                    }
                    if(j == m) idx.push_back(i+1);
                }
                if(i<n-m){
                    t = (d*(t - txt[i]*h) + txt[i+m])%q;
                    
                    if(t<0) t = t+q;
                }
            }
        if(idx.empty()) idx.push_back(-1);
        return idx;
        }
     
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector <int> res = ob.search(pat, S);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}

// Contributed By: Pranay Bansal

// } Driver Code Ends
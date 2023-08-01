//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
        void getZarr(string str,int len,vector<int>& Z){
            int L=0,R=0,k;
            //L R is interval;
            
            
            for(int i=1;i<len;i++){
                if(i>R){
                    L = R = i;
                    while(R<len && str[R-L] == str[R]) {
                        R++;
                    }
                    Z[i] = R-L;
                    R--;
                }
                else{
                    k = i-L;
                    if(Z[k] < R-i+1){
                        Z[i] = Z[k];
                    }
                    else{
                        L=i;
                        while(R<len && str[R-L] == str[R]) R++;
                        Z[i] = R-L;
                        R--;
                    }
                }
            }
            
        }
        vector <int> search(string pat, string txt)
        {
            string concat = pat + "$" + txt;
            int len = concat.length();
            
            vector<int> Z(len);
            
            vector<int> ans;
            
            getZarr(concat,len,Z);
            
            for(int i=0;i<len;i++){
                if(Z[i] == pat.length()) ans.push_back(i-pat.length());
            }
            if(ans.empty()) ans.push_back(-1);
            
        return ans;
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
        if(res.size()==0)
            cout<<"-1 ";
        else
            for (int i : res)
                cout << i << " ";
        cout << endl;
    }
    return 0;
}


// } Driver Code Ends
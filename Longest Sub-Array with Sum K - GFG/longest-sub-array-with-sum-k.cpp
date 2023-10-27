//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int lenOfLongSubarr(int A[],  int N, int K) 
    {   
        map<int,int> mp;
        // sum , index at which sum occurred
        // Initially sum = 0
        int sum =0;
        
        int maxLen = 0;
        
        for(int i = 0 ; i < N ; i++ ){
            sum += A[i];
            if(sum == K){
                int len = i+1;
                maxLen = max(maxLen,len);
            }
            
            int remaining = sum - K;
            
            if(mp.find(remaining) != mp.end()){
                int len = i-mp[remaining];
                maxLen = max(maxLen,len);
            }
            if(mp.find(sum) == mp.end()){
                mp[sum] = i;
            }
        }
       return maxLen; 
    } 

};

//{ Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends
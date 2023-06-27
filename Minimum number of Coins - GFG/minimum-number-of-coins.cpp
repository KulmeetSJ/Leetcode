//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> minPartition(int N)
    {
        int currency[]={2000,500,200,100,50,20,10,5,2,1};
        //int currency2[] = {1,2,5,10,20,50,100,200,500,2000};
        
        int size = 10;
        
        int minCoins = 0;
        int target = N;
        vector<int> ans;
        
        for(int i=0;i<size;){
            if(currency[i]<=target){
                target = target - currency[i];
                minCoins++;
                ans.push_back(currency[i]);
                continue;
            }
            else
               i++;
        }
    return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        vector<int> numbers = ob.minPartition(N);
        for(auto u: numbers)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends
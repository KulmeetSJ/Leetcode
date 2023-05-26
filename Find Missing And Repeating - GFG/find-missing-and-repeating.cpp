//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        int size = arr.size();
        
        unordered_map<int,int> mp;
        
        for(int i=1;i<=n;i++)
        {
            mp[i] = 0;
        }
        
        for(int i=0;i<size;i++)
        {
            mp[arr[i]]++;
        }
        
        int repeating = -1,missing = -1;
        
        for(auto i:mp)
        {
            if(i.second == 0)
            missing = i.first;
            else if(i.second == 2)
            repeating = i.first;
        }
        
        return {repeating,missing};
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends
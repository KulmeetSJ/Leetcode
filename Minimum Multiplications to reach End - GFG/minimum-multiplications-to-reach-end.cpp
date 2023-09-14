//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

#define mod 100000

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        vector<int> dist(100000,1e9);
        //Store number,steps
        queue<pair<int,int>> q;
        
        q.push({0,start});
        dist[start] = 0;
        
        while(!q.empty()){
            int num = q.front().second;
            int steps = q.front().first;
            q.pop();
            
            if(num == end) return steps;
            
            for(int i:arr){
                int temp = i * num % mod;
                if(steps + 1 < dist[temp]){
                    dist[temp] = steps+1;
                    q.push({steps+1,temp});
                }
                
            }
        }
    return -1;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends
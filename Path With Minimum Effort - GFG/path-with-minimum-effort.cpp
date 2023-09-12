//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int MinimumEffort(vector<vector<int>>& heights) {
        int m = heights.size() , n=heights[0].size();
        vector<vector<int>> dist(m,vector<int>(n,1e9));
        
        //Make a min heap of dist,p,q
        priority_queue<pair<int,pair<int,int>> , vector<pair<int,pair<int,int>>> , greater<pair<int,pair<int,int>>> > pq;
        dist[0][0] = 0;
        pq.push({0,{0,0}});
        
        vector<pair<int,int>> neighbours = {{0,1},{1,0},{-1,0},{0,-1}};
        
        
        while(!pq.empty()){
            int current_diff = pq.top().first;
            int p = pq.top().second.first;
            int q = pq.top().second.second;
            pq.pop();
            
            if(p == m-1 && q == n-1){
                return current_diff;
            }
            
            for(auto i:neighbours){
                int new_p = p + i.first;
                int new_q = q + i.second;
                
                if(new_p >=0 && new_p <m && new_q >=0 && new_q < n){
                    int new_diff = abs(heights[p][q] - heights[new_p][new_q]);
                    int diff = max(new_diff,current_diff);
                    if(diff < dist[new_p][new_q]){
                        dist[new_p][new_q] = diff;
                        pq.push({diff,{new_p,new_q}});
                    }
                    
                    
                }
            }
        }
       return -1; 
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n,m; cin>>n>>m;
        vector<vector<int>> heights;
       
        for(int i=0; i<n; ++i){
            vector<int> temp;
            for(int j=0; j<m; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            heights.push_back(temp);
        }
       
        Solution obj;
        cout<<obj.MinimumEffort(heights)<<"\n";
    }
    return 0;
}
// } Driver Code Ends
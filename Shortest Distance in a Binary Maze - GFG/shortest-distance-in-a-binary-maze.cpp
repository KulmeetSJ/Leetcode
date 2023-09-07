//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        
        if(source.first==destination.first && source.second==destination.second) return 0; 
        
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dist(m,vector<int>(n,1e9));
        queue<pair<int,pair<int,int>>> q;
        dist[source.first][source.second] = 0;
        q.push({0,{source.first,source.second}});
        
        vector<pair<int,int>> dir = {{0,1}, {0,-1} , {-1,0}, {1,0}};
        
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            int dis = p.first;
            
            int u = p.second.first;
            int v = p.second.second;
            
            for(auto it:dir){
                int new_u = u + it.first;
                int new_v = v + it.second;
                if(new_u >=0 && new_u<m && new_v >=0 && new_v < n && grid[new_u][new_v] == 1 && dis+1 < dist[new_u][new_v])
                {
                    dist[new_u][new_v] = 1 + dis;
                    if(new_u == destination.first && new_v == destination.second) return dist[new_u][new_v];
                    q.push({1+dis , {new_u,new_v}});
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
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends
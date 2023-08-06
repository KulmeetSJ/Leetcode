//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

typedef pair<int,int> pi ;


class Solution {
  public:
    void dfs(int row,int col,vector<vector<int>>& grid,vector<vector<int>> &vis,vector<pi> &vec,
    vector<pi> dir,int m,int n,int row0,int col0){
        vis[row][col] = 1;
        vec.push_back({row-row0,col-col0});
        
        for(auto i:dir){
            int nrow = row + i.first;
            int ncol = col + i.second;
            if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && grid[nrow][ncol] == 1&& vis[nrow][ncol] == 0 ){
                dfs(nrow,ncol,grid,vis,vec,dir,m,n,row0,col0);
            }
        }
    }
    int countDistinctIslands(vector<vector<int>>& grid) {
        int m = grid.size(),n=grid[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        
        vector<pi> dir = {{0,1},{1,0},{-1,0},{0,-1}};
        
        set<vector<pi>> st;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1 && !vis[i][j]){
                vector<pi> vec;
                dfs(i,j,grid,vis,vec,dir,m,n,i,j);
                st.insert(vec);
                }
            }
        }
    return st.size();
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
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends
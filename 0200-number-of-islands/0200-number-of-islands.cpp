class Solution {
public:
    void bfs(int i,int j,vector<vector<char>>& grid,vector<vector<bool>>& vis){
        queue<pair<int,int>> q;
        int m=grid.size();
        int n = grid[0].size();
        
        q.push({i,j});
        vis[i][j] = true;
        
        vector<pair<int,int>> directions = {{-1,0},{1,0},{0,-1},{0,1}};
        
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            for(auto it:directions){
                int nrow = row + it.first;
                int ncol = col + it.second;
                
                if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && grid[nrow][ncol] == '1' && !vis[nrow][ncol]){
                    vis[nrow][ncol]=true;
                    q.push({nrow,ncol});
                }
            }   
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> vis(m,vector<bool>(n,false));
   
        int cnt = 0;
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++){
                if(!vis[i][j] && grid[i][j] == '1'){
                    cnt++;
                    bfs(i,j,grid,vis);
                }
            }
        }
       
    return cnt;
    }
};
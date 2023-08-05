class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size(),n=grid[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        
        queue<pair<int,int>> q;
        
        for(int i=0;i<n;i++){
            //Left boundary
            if(grid[0][i]==1 && !vis[0][i]) q.push({0,i}),vis[0][i]=1;
            //Right boundary
            if(grid[m-1][i]==1 && !vis[m-1][i]) q.push({m-1,i}),vis[m-1][i]=1;
        }
        for(int i=0;i<m;i++){
            //Top boundary
            if(grid[i][0]==1 && !vis[i][0]) q.push({i,0}),vis[i][0]=1;
            //Bottom boundary
            if(grid[i][n-1]==1 && !vis[i][n-1]) q.push({i,n-1}),vis[i][n-1]=1;
        }
        
        
        vector<pair<int,int>> directions= {{-1,0},{0,1},{1,0},{0,-1}};
        
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            cout<<row<< " "<<col<<endl;
            q.pop();
            
            for(auto i:directions){
                int nrow = row + i.first;
                int ncol = col + i.second;
                if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && grid[nrow][ncol] == 1 && vis[nrow][ncol]==0){
                    vis[nrow][ncol] = 1;
                    q.push({nrow,ncol});
                }
            }
        }
        
        int steps = 0;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1 && vis[i][j] == 0) steps++;
            }
        }
    return steps;
    }
};
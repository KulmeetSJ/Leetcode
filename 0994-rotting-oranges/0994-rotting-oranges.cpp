class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int,int>> q;
        int totalOranges = 0;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                }
                if(grid[i][j] != 0) totalOranges++;
            }
        }
        
        
        
        if(totalOranges == q.size()) return 0;
        
        if(q.empty()) return -1;
        
        vector<pair<int,int>> directions = {{-1,0},{0,1},{1,0},{0,-1}};
        int minutes = 0;
        int cnt = 0;
        
        while(!q.empty()){
            int k = q.size();
            
            cnt += k; // For checking whether all oranges are rotten or not
            while(k--){
                int row = q.front().first;
                int col = q.front().second;
                q.pop();
                for(auto it:directions){
                    int nrow = row+it.first;
                    int ncol = col+it.second;
                    
                    if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && grid[nrow][ncol] == 1){
                        grid[nrow][ncol] = 2;
                        q.push({nrow,ncol});
                    }
                } 
            }
            if(!q.empty()) minutes++;
        }
     if(totalOranges == cnt) return minutes;
     else return -1;    
    }
};
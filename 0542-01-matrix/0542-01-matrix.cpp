class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(),n = mat[0].size();
        vector<vector<int>> ans(m,vector<int>(n));
        vector<vector<int>> vis(m,vector<int>(n,0));
        
        queue<pair<pair<int,int>,int>> q;
        
        //First push all indexes where mat[i][j] == 0 , to the queue and mark their min distance = 0
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j] == 0){
                    q.push({{i,j},0});
                    ans[i][j] = 0;
                    vis[i][j] = 1;
                }
            }
        }
        
        vector<pair<int,int>> directions = {{-1,0},{0,1},{1,0},{0,-1}};
        
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int dist = q.front().second;
            q.pop();
            
            for(auto i:directions){
                int nrow = row + i.first;
                int ncol = col + i.second;
                
                if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && mat[nrow][ncol]!=0 && !vis[nrow][ncol]){
                    vis[nrow][ncol] = 1;
                    ans[nrow][ncol] = dist+1;
                    q.push({{nrow,ncol},dist+1});   
                }
            }
            
        }
        
     return ans; 
    }
};
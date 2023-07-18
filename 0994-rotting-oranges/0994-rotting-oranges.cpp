class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        int totalOranges = 0;
        queue<pair<int,int>> q;
        
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]!=0) totalOranges++;
                if(grid[i][j] == 2){
                    q.push({i,j});
                }
            }
        }
        
        if (totalOranges == 0 ) return 0;
        if (q.empty()) return -1;
        
        int dx[4] = {0,0,1,-1};
        int dy[4] = {1,-1,0,0};
        
        int minutes = 0,cnt = 0;
        
        while(!q.empty()){
            int k = q.size();
            cnt+=k;
            while(k--){
                int x = q.front().first , y = q.front().second;
                q.pop();
                for(int i=0;i<4;i++){
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    if(nx<0 || ny<0 || nx>=grid.size() || ny>=grid[0].size() || grid[nx][ny]!= 1 ) continue;
                    grid[nx][ny] = 2;
                    q.push({nx,ny});
                }
            }
            if(!q.empty()) minutes++;
        }
        
        if(cnt == totalOranges) return minutes;
        else return -1;
    }
};
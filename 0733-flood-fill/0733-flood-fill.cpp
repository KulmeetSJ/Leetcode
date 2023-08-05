class Solution {
public:
    void dfs(int i,int j,int ini,int color,vector<vector<int>>& ans,vector<pair<int,int>> &directions){
        ans[i][j] = color;
        int m = ans.size();
        int n = ans[0].size();
        for(auto neighbours:directions){
            int row = i+neighbours.first;
            int col = j+neighbours.second;
            if(row >=0 && row<m && col>=0 && col<n && ans[row][col] == ini && ans[row][col] != color){
                dfs(row,col,ini,color,ans,directions);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size(),n=image[0].size();
        int ini=image[sr][sc];
        
        if(ini == color) return image;
        
        vector<vector<int>> ans = image;
        vector<pair<int,int>> directions = {{-1,0},{0,1},{1,0},{0,-1}};
    
        dfs(sr,sc,ini,color,ans,directions);
    return ans;       
    }
};
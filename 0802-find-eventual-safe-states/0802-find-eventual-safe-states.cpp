class Solution {
public:
    bool dfs(int node,vector<int> &vis,vector<int> &pathVis,vector<vector<int>> &adj,vector<int>& check){
        vis[node] = 1;
        pathVis[node] = 1;
        check[node] = 0;
        for(auto i: adj[node]){
            if(!vis[i]){
                if(dfs(i,vis,pathVis,adj,check)) return true;
            }
            else if(pathVis[i] == 1){
                return true;
            }
        }
        //Suppose a call for a node reached here , it means it is not a part of any cycle so we can mark it check[node] = 1 here
        check[node] = 1;
        pathVis[node] = 0;
    return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> safe;
        int n = graph.size();
        
        vector<vector<int>> adjList(n);
        
        for(int i=0;i<n;i++){
            for(int j=0;j<graph[i].size();j++){
                adjList[i].push_back(graph[i][j]);
            }
        }
        
        //Now we'll detect cycle
        vector<int> vis(n,0);
        vector<int> pathVis(n,0);
        //We ll use a check array which will store whether node is a safe node or not
        vector<int> check(n,0);
        
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,vis,pathVis,adjList,check);
            }
        }
        
        for(int i=0;i<check.size();i++){
            if(check[i] == 1){
                safe.push_back(i);
            }
        }
        
        
    return safe;
    }
};
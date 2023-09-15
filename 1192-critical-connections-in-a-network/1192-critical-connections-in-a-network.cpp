class Solution {
    int timer = 1;
    void dfs(int node,int parent,vector<int> &vis,vector<vector<int>> &adj, int *insertion_time , int *lowest_time,vector<vector<int>> &bridges){
        vis[node] = 1;
        insertion_time[node] = lowest_time[node] = timer;
        timer++;
        for(auto it:adj[node]){
            if(it == parent) continue;
            if(!vis[it]){
                dfs(it,node,vis,adj,insertion_time,lowest_time,bridges);
                lowest_time[node] = min(lowest_time[node] , lowest_time[it]);
                //Checking whether edge is a bridge
                if(lowest_time[it] > insertion_time[node] ){
                 bridges.push_back({it,node});
                }
            }
            else{
                lowest_time[node] = min(lowest_time[it],lowest_time[node]);
            }
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        
        for(auto it:connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> vis(n,0);
        
        int insertion_time[n] , lowest_time[n];
        
        vector<vector<int>> bridges;
        
        dfs(0,-1,vis,adj,insertion_time,lowest_time,bridges);
        
    return bridges;
    }
};
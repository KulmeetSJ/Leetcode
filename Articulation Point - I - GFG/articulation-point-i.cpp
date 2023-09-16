//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
    int timer = 0;
    void dfs(int node,int parent,vector<int> &vis,int *insertion_time , int *low_time ,vector<int> &mark,
    vector<int> adj[] ){
        vis[node] = 1;
        insertion_time[node] = low_time[node] = timer;
        timer++;
        int child = 0;
        for(auto it:adj[node]){
            if(it == parent) continue;
            if(!vis[it]){
                dfs(it,node,vis,insertion_time,low_time,mark,adj);
                low_time[node] = min(low_time[node],low_time[it]);
                if(low_time[it] >= insertion_time[node] && parent != -1){
                    mark[node] = 1;
                }
                child++;
            }
            else{
                low_time[node] = min(low_time[node],insertion_time[it]);
            }
        }
        if(child > 1 && parent == -1) mark[node] = 1;
    }
  public:
    
    vector<int> articulationPoints(int n, vector<int>adj[]) {
        vector<int> vis(n,0);
        int insertion_time[n] , low_time[n];
        
        vector<int> mark(n,0);
        
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,-1,vis,insertion_time,low_time,mark,adj);
            }
        }
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(mark[i] == 1){
                ans.push_back(i);
            }
        }
        if(ans.size() == 0) return {-1};
        else return ans;
    }
};

//{ Driver Code Starts.

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		vector<int> ans = obj.articulationPoints(V, adj);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends
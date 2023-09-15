//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	private:
	void dfs(int node ,vector<vector<int>>& adj,vector<int> &vis,stack<int> &st){
	    vis[node] = 1;
	    
	    for(auto it:adj[node]){
	        if(!vis[it]){
	            dfs(it,adj,vis,st);
	        }
	    }
	    st.push(node);
	}
	private:
	void dfs3(int node, vector<int>& vis,vector<vector<int>> &adjT){
	    vis[node] = true;
	    
	    for(auto it:adjT[node]){
	        if(!vis[it]){
	            dfs3(it,vis,adjT);
	        }
	    }
	}
	public:
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        //Step 1: Perform a DFS and sort the nodes based on their finishing time
        stack<int> st;
        vector<int> vis(V,0);
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,adj,vis,st);
            }
        }
        
        //Step 2: Reverse all the edges
        vector<vector<int>> adjT(V);
        
        for(int i=0;i<V;i++){
            vis[i] = 0;
            for(auto it:adj[i]){
                adjT[it].push_back(i);
            }
        }
        
        
        
        int scc = 0;
        //Step 3: Perform dfs based on elements in stack
        while(!st.empty()){
            int node = st.top();
            st.pop();
            if(!vis[node]){
                dfs3(node,vis,adjT);
                scc++;
            }
        }
    return scc;
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends
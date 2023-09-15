//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Disjointset{
    private:
     vector<int> parent,rank;
    public:
     
     Disjointset(int n){
         parent.resize(n);
         rank.resize(n,0);
         for(int i=0;i<n;i++){
             parent[i] = i;
         }
     }
    
    int findParent(int u){
        if(parent[u] == u ) return u;
        
        return parent[u] = findParent(parent[u]);
    }
    
    void unionByRank(int u,int v){
        int ultimate_parent_u = findParent(u);
        int ultimate_parent_v = findParent(v);
        if(ultimate_parent_u == ultimate_parent_v) return;
        
        if(rank[ultimate_parent_u] < rank[ultimate_parent_v]){
            parent[ultimate_parent_u] = ultimate_parent_v;
        }
        else if(rank[ultimate_parent_u] > rank[ultimate_parent_v]){
            parent[ultimate_parent_v] = ultimate_parent_u;
        }
        else{
            parent[ultimate_parent_u] = ultimate_parent_v;
            rank[ultimate_parent_u]++;
        }
    }
     
};

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
       vector<pair<int,pair<int,int>>> edges;
       for(int i=0;i<V;i++){
           for(auto it:adj[i]){
               int adjNode = it[0];
               int wt = it[1];
               int node = i;
               edges.push_back({wt,{node,adjNode}});
           }
       }
       Disjointset ds(V);
       sort(edges.begin(),edges.end());
       int sum = 0;
       
       for(auto it:edges){
           int wt = it.first;
           int u = it.second.first;
           int v = it.second.second;
           
           if(ds.findParent(u) == ds.findParent(v)){
               continue;
           }
           else{
                sum += wt;
                ds.unionByRank(u,v);
           }
               
        }
       

     return sum;   
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> adj(n+1);
        
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        
        vector<int> dist(n+1,1e9);
        vector<int> parent(n+1);
        
        for(int i=1;i<parent.size();i++){
            parent[i] = i;
        }
        
        dist[1] = 0;
        set<pair<int,int>> st;
        
        st.insert({0,1});
        
        while(!st.empty()){
            auto temp = *(st.begin());
            int node = temp.second;
            int dis = temp.first;
            st.erase(temp);
            for(auto adjNodes: adj[node]){
                if(st.find(adjNodes) == st.end()){
                int adjNode = adjNodes.first;
                int edge_weight = adjNodes.second;
                if(dis + edge_weight < dist[adjNode]){
                    dist[adjNode] = dis + edge_weight;
                    st.insert({dist[adjNode],adjNode});
                    parent[adjNode] = node;
                }
                }
            }
        }
        if(dist[n] == 1e9) return {-1};
        
        vector<int> ans;
        int node = n;
        while(parent[node] != node){
            ans.push_back(node);
            node = parent[node];
        }
        //Push source
        ans.push_back(1);
        
        reverse(ans.begin(),ans.end());
        
    return ans;
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class DisjointSet{
    public:
    vector<int> parent,size;
    DisjointSet(int n){
        parent.resize(n);
        size.resize(n,1);
        for(int i=0;i<n;i++) {
            parent[i] = i;
        }
    }
    
    int findParent(int u){
        if(parent[u] == u) return u;
        
        return parent[u] = findParent(parent[u]);
    }
    
    void unionBySize(int u,int v){
        int pu = findParent(u);
        int pv = findParent(v);
        if(pu == pv) return;
        
        if(size[pu] < size[pv]) {
            size[pv] += size[pu];
            parent[pu] = pv;
        }
        else{
            size[pu] += size[pv];
            parent[pv] = pu;
        }
    }
};
class Solution {
  public:
    int Solve(int n, vector<vector<int>>& edge) {
        DisjointSet ds(n);
        
        int cntExtras = 0;
        for(auto it:edge){
            int u = it[0] , v = it[1];
            if(ds.findParent(u) == ds.findParent(v)) cntExtras++;
            else ds.unionBySize(u,v);
        }
        int connectedComponents = 0;
        for(int i=0;i<n;i++){
            if(ds.parent[i] == i) connectedComponents++;
        }
        int ans = connectedComponents -1;
        if(cntExtras >= ans) return ans;
        else return -1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 2; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution Obj;
        cout << Obj.Solve(n, adj) << "\n";
    }
    return 0;
}
// } Driver Code Ends
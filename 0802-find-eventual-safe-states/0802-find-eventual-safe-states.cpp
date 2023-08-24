class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<vector<int>> adjRev(V);
        
        for(int i=0;i<V;i++){
            for(auto it:graph[i]){
                adjRev[it].push_back(i);
            }
        }
        
        
        vector<int> inDegree(V,0);
        
        for(int i=0;i<V;i++){
            for(auto it:adjRev[i]){
                inDegree[it]++;
            }
        }
        
        queue<int> q;
        
        for(int i=0;i<V;i++){
            if(inDegree[i] == 0){
                q.push(i);
            }
        }
        
        
        vector<int> safe;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            safe.push_back(node);
            
            for(auto it:adjRev[node]){
                inDegree[it]--;
                if(inDegree[it] == 0){
                    q.push(it);
                }
            }
        }
        
        sort(safe.begin(),safe.end());
        
        return safe;        
    }
};
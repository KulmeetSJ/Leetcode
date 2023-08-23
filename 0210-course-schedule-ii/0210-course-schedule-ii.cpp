class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
         vector<vector<int>> adj(numCourses);
        for(int i=0;i<prerequisites.size();i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        
        vector<int> inDegree(numCourses,0);
        for(int i=0;i<numCourses;i++){
            for(auto it:adj[i]){
                inDegree[it]++;
            }
        }
        
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(inDegree[i] == 0){
                q.push(i);
            }
        }
        
        vector<int> topo;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for(auto it:adj[node]){
                inDegree[it]--;
                if(inDegree[it] == 0)
                q.push(it);
            }
        }
        
        if(topo.size() == numCourses) return topo;
        else return {};
    }
};
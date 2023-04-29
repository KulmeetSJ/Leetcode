class Solution {
public:
    int dsu(vector<int>& parent,int x)
    {
        if(parent[x] == x) return x;
        else
            return parent[x] = dsu(parent,parent[x]);
    }
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        vector<int> parent(n,-1);
        vector<bool> ans(queries.size(),false);
        
        for(int i=0;i<n;i++)
            parent[i] = i;
        
        for(int i=0;i<edgeList.size();i++)
        {
            swap(edgeList[i][0],edgeList[i][2]);
        }
        
        sort(edgeList.begin(),edgeList.end());
        
        vector<pair<int,int>> arr;
        
        for(int i=0;i<queries.size();i++)
            arr.push_back({queries[i][2],i});
        
        sort(arr.begin(),arr.end());
        
        int j = 0;
        
        for(int i = 0; i < arr.size(); i++)
        {
            while(j < edgeList.size() && edgeList[j][0] < arr[i].first)
            {    
                
                int u = edgeList[j][1],v = edgeList[j][2];
                
                int pu = dsu(parent,u),pv = dsu(parent,v);
                
                if(pu != pv)
                    parent[pu] = pv;
                
                j++;
            }
            
            int x = queries[arr[i].second][0],y = queries[arr[i].second][1];
            
            int px = dsu(parent,x),py = dsu(parent,y);
            
            if(px == py)
                ans[arr[i].second] = true;
            
        }
        return ans;
    }
};
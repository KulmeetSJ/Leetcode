class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> mp;

        for(auto it:nums)
        {
            mp[it]++;
        }
        vector<pair<int,int>> v;

        for(auto it: mp)
        {
            v.push_back({it.second,it.first});
        }
        
        sort(v.begin(),v.end(),[&](auto &a,auto &b)
        {
            return a>b;
        });
        
        vector<int> ans;
        
        
        for(int it=0;it<k;it++)
        {
            ans.push_back(v[it].second);
            
        } 

        
        return ans;
    }
};
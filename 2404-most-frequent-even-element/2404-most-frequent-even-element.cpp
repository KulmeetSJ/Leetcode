class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        map<int,int> mp;
        
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }
        
        int freq = INT_MIN;
        int ans = -1;
        
        for(auto i:mp)
        {
            if(i.first %2 == 0)
            {
                if(freq < i.second)
                {
                    freq = i.second;
                    ans = i.first;
                }
                else if(freq == i.second)
                {
                    if(i.first < ans)
                        ans = i.first;
                }
            }
        }
    return ans;
    }
};
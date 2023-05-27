class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        int ele;
        
        for(int i=0;i<nums.size();i++)
        {
            if(cnt == 0)
            {
                ele = nums[i];
                cnt++;
                continue;
            }
            if(ele == nums[i])
                cnt++;
            else
                cnt--;
        }
        
        cnt=0;
        
        for(int i=0;i<nums.size();i++)
        {
            if(ele == nums[i])
                cnt++;
        }
        
        if(cnt >= (n/2))
            return ele;
        
       return -1; 
    }
};
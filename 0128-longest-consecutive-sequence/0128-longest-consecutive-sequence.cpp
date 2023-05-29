class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n  = nums.size();
        int cnt = 1 , lastSmaller = INT_MIN , longest = 0;
        
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<n;i++)
        {
            if(nums[i]-1 == lastSmaller)
            {
                cnt++;
                lastSmaller = nums[i];
            }
            else if(nums[i] == lastSmaller)
            {
                continue;
            }
            else{
                cnt = 1;
                lastSmaller = nums[i];
            }
            longest = max(longest,cnt);
        }
    return longest;
    }
};
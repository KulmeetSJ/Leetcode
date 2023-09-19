class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MAX;
        
        int low = 0, high = n-1;
        
        while(low <= high){
            int mid = (low + high)/2;
            
            //If Left half sorted , get lowest and eliminate left half
            if(nums[low] == nums[mid] && nums[mid] == nums[high]){
                ans = min(nums[mid],ans);
                low++,high--;continue;
            }
            if(nums[low] <= nums[mid]){
                ans = min(nums[low],ans);
                low = mid+1;
            }
            else{
                ans = min(nums[mid],ans);
                high = mid-1;
            }
        }
    return ans;
    }
};
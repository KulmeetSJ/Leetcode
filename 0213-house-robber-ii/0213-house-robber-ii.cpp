class Solution {
public:
     int space_opt(vector<int> nums){
        int n = nums.size();
        int prev = nums[0];
        int sprev = 0;
        int curr;
        
        for(int i = 1;i<n;i++){
            int pick = nums[i];
            if(i>1) pick += sprev;
            
            int notPick = prev;
            curr = max(pick,notPick);
            sprev = prev;
            prev = curr;
        }
    return prev;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        vector<int> a1(nums.begin()+1,nums.end());
        vector<int> a2(nums.begin(),nums.end()-1);
        
        return max(space_opt(a1),space_opt(a2));
        
    }
};
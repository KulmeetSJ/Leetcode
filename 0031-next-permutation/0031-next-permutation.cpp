class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int break_point = -1;
        int n = nums.size();
        
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                break_point = i;
                break;
            }
        }
        if(break_point == -1){
            reverse(nums.begin(),nums.end());
            return;
        }
        
        int mini = INT_MAX;
        int mini_index = break_point;
        
        for(int i=n-1;i>=break_point;i--){
            if(nums[i] > nums[break_point]){
                if(mini > nums[i]){
                    mini = nums[i];
                    mini_index = i;
                }
            }
        }
        
        swap(nums[mini_index],nums[break_point]);
        
        reverse(nums.begin()+break_point+1,nums.end());
    }
};
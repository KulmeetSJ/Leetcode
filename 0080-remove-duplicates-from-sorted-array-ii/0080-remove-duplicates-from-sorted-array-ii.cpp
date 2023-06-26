class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size() ;
        if(n==1) return 1;
        int i=0;
        int j=i+1;
        bool first = true;
        
        while(j<n){
            if(nums[i] == nums[j] && first){
                if(i+1 != j){
                    nums[i+1] = nums[j];
                }
                i++;
                j++;
                first = false;
                
            }
            else if(nums[i] == nums[j] && !first){
                j++;
            }
            else if(nums[i] != nums[j]){
                nums[i+1] = nums[j];
                i++;
                j++;
                first = true;
            }
        }
    return i+1;
    }
};
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 1;
        int ele = nums[0];
        
        for(int i=1;i<nums.size();i++){
            if(cnt == 0){
                ele = nums[i];
                cnt=1;
                continue;
            }
            if(nums[i] == ele){
                cnt++;
            }
            else{
                cnt--;
            }
            
        }
        
        cnt = 0;
        for(int i=0;i<nums.size();i++){
            if(ele == nums[i]){
                cnt++;
            }
        }
        
        if(cnt >= nums.size()/2) return ele;
        else return -1;
    }
};
class Solution {
public:
    void merge(int low,int mid,int high,vector<int>& nums){
        int l = low , r = mid+1;
        vector<int> temp;
        while(l<=mid && r<=high){
            if(nums[l]<=nums[r]){
                temp.push_back(nums[l++]);
            }
            else
                temp.push_back(nums[r++]);
        }
        
        while(l<=mid){
            temp.push_back(nums[l]);
            l++;
        }
        while(r<=high){
            temp.push_back(nums[r]);
            r++;
        }
        for(int i=low;i<=high;i++){
            nums[i] = temp[i-low];
        }
    }
    void mergeSort(int low,int high,vector<int>& nums){
        if(low>=high) return;
        int mid = (low+high)/2;
        mergeSort(low,mid,nums);
        mergeSort(mid+1,high,nums);
        merge(low,mid,high,nums);
    }
    vector<int> sortArray(vector<int>& nums) {
        int low = 0 , high = nums.size()-1;
        mergeSort(low,high,nums);
    return nums;
    }
};
class Solution {
public:
    void merge(vector<int>& nums,int low,int mid,int high){
        int i = low , j = mid+1,k = low;
        int temp[high+1];
        while(i<=mid && j<=high){
            if(nums[i] <= nums[j]){
                temp[k++] = nums[i];
                i++;
            }
            else{
                temp[k++] = nums[j];
                j++;
            }
        }
        
        while(i<=mid){
            temp[k++] = nums[i];
            i++;
        }
        while(j<=high){
            temp[k++] = nums[j];
            j++;
        }
        
        for(int i=low;i<=high;i++){
            nums[i] = temp[i];
        }
    }
    void mergeSort(vector<int>& nums,int low,int high){
        if(low >=high) return;
        int mid = (low+high)/2;
        
        mergeSort(nums,low,mid);
        mergeSort(nums,mid+1,high);
        
        merge(nums,low,mid,high);
    }
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        mergeSort(nums,0,n-1);
    return nums;
    }
};
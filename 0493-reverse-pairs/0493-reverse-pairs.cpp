class Solution {
public:
    int count = 0;
    void merge(int low,int mid,int high,vector<int>& nums)
    {
        vector<int> temp;
        int i = low;
        int j = mid+1;
        
        while(i<=mid && j<=high)
        {
            if(nums[i] <=nums[j])
            {
                temp.push_back(nums[i]);
                i++;
            }
            else{
                temp.push_back(nums[j]);
                j++;
            }
        }
        
        while(i<=mid)
            temp.push_back(nums[i++]);
        
        while(j<=high)
            temp.push_back(nums[j++]);
        
        for(int i=low;i<=high;i++)
        {
            nums[i] = temp[i-low];
        }
    }
    
    void solve(int low,int mid ,int high,vector<int>& nums)
    {
        int j = mid+1;
        
        for(int i=low;i<=mid;i++)
        {   
            
            while(j<=high && nums[i] > (long long)2*nums[j])
            {
                j++;
            }
            count += j-(mid+1);
        }
    }
    
    void mergeSort(int low,int high,vector<int>& nums)
    {
        if(low>=high) return;
        
        int mid = (low+high)/2;
        mergeSort(low,mid,nums);
        mergeSort(mid+1,high,nums);
        solve(low,mid,high,nums);
        merge(low,mid,high,nums);
    }
    
    
    int reversePairs(vector<int>& nums) {
        mergeSort(0,nums.size()-1,nums);
        
    return count;
    }
};
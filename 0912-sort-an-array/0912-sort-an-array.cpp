class Solution {
public:
    void heapify(vector<int>& nums,int i,int n){
        int largest = i;
        int lchild = 2*i+1 , rchild = 2*i+2;
        if(lchild<n && nums[lchild] > nums[largest]){
            largest = lchild;
        }
        if(rchild < n && nums[rchild] > nums[largest]){
            largest = rchild;
        }
        
        if(largest != i){
            swap(nums[i],nums[largest]);
            heapify(nums,largest,n);
        }
    }
    
    void heapSort(vector<int>& nums,int n){
        for(int i=n/2-1;i>=0;i--){
            heapify(nums,i,n);
        }
        
        for(int i=nums.size()-1;i>=0;i--){
            swap(nums[0],nums[i]);
            heapify(nums,0,i);
        }
    }
    
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        heapSort(nums,n);
    return nums;
    }
};
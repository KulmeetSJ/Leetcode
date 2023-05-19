class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        for(int i=m,j=0;j<n;i++)
        {
            nums1[i] = nums2[j++];
        }
        
        int len = m+n;
        int gap = (len/2) + len%2 ;
        
        while(gap)
        {
            int left = 0;
            int right = gap;
            while(right < len)
            {
                if(nums1[left] <= nums1[right])
                {
                    left++;
                    right++;
                }
                else
                {
                    swap(nums1[left],nums1[right]);
                    left++;
                    right++;
                }
            }
            if(gap <=1) gap = 0;
            else gap = gap/2 + gap%2;
        }
    }
};
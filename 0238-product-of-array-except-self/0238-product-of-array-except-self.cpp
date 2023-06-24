class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> pre(n), suff(n);
        
        pre[0] = nums[0];
        for(int i=1;i<n;i++){
            pre[i] = pre[i-1]*nums[i];
        }
        
        for(auto i:pre){
            cout<<i<<" ";
        }
        cout<<endl;
        
        suff[n-1] = nums[n-1];
        
        for(int j=n-2;j>=0;j--){
            suff[j] = suff[j+1] * nums[j];
        }
        
        for(auto i:suff){
            cout<<i<<" ";
        }
        cout<<endl;
        
        vector<int> ans(n);
        
        for(int i=0;i<n;i++){
            if(i==0){
                ans[i] = suff[i+1];
            }
            else if(i == n-1){
                ans[i] = pre[i-1];
            }
            else{
                ans[i] = pre[i-1] * suff[i+1];
            }
        }
    return ans;
    }
};
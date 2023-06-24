class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> pre(n),suff(n);
        
        int mx = INT_MIN;
        
        for(int i=0;i<n;i++){
            mx = max(mx,height[i]);
            pre[i] = mx;
        }
        
       
        mx = INT_MIN;
        for(int j=n-1;j>=0;j--){
            mx = max(mx,height[j]);
            suff[j] = mx;
        }

        int trappedWater = 0;
        for(int i=0;i<n;i++){
            trappedWater += (min(suff[i],pre[i]) - height[i]);
        }
        return trappedWater;
    }
};
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size() ;
        vector<int> pre(n,0) , suff(n,0);
        
        int mx = INT_MIN;
        for(int i=0;i<n;i++){
            mx = max(mx,height[i]);
            pre[i] = mx;
        }
        
        mx = INT_MIN;
        for(int i=n-1;i>=0;i--){
            mx = max(mx,height[i]);
            suff[i] = mx;
        }
        
        int trappedWater = 0;
        for(int i=0;i<n;i++){
            trappedWater += min(pre[i],suff[i])-height[i];
        }
        
        return trappedWater;    
    }
};
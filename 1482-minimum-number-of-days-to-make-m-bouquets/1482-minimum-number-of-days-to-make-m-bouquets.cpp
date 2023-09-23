class Solution {
public:
    bool check(int days,vector<int>& bloomDay,int m,int k){
        int bouquet_cnt = 0;
        int adjacent_cnt = 0;
        for(int i=0;i<bloomDay.size();i++){
            if( bloomDay[i] <= days){
                adjacent_cnt++;
            }
            else{
                bouquet_cnt += (adjacent_cnt/k);
                adjacent_cnt = 0;
            }
        }
        bouquet_cnt += (adjacent_cnt/k);
        return bouquet_cnt >=m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int mini = *min_element(bloomDay.begin(),bloomDay.end());
        int maxi = *max_element(bloomDay.begin(),bloomDay.end());
        
        int n = bloomDay.size();
        long long val = k * 1LL * m * 1LL;
        if(n< val) return -1;
        
        int ans = -1;
        
        while(mini<=maxi){
            int mid = (maxi+mini)/2;
            if(check(mid,bloomDay,m,k)){
                maxi = mid-1;
            }
            else {
                mini = mid+1;
            }
        }
    return mini;
    }
};
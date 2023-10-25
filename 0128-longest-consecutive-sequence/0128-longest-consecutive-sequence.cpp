class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        int maxi  = INT_MIN;
        
        set<int> st(nums.begin(),nums.end());
        
        for(auto it:st){
            if(st.find(it-1) == st.end()){
              int cnt = 1;
              int x = it;
                while(st.find(x+1) != st.end()){
                    x++;
                    cnt++;
                }
            maxi = max(maxi,cnt);
        }
        }
        return maxi;
    }
};
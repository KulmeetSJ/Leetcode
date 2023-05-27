class Solution {
public:
    int uniquePaths(int m, int n) {
        int N = m + n - 2;
        int R = m-1;
        
        double ans = 1;
        
        for(int i=1;i<=R;i++)
        {
            ans = ans * (N-R+i);
            ans = ans / i;
        }
    return (int)ans;
    }
};
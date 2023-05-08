class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int sum = 0;
        int n = mat.size();
        int m = mat[0].size();
        
        vector<vector<int>> temp(n,vector<int>(m,0));
        
        if(n==1)
            return mat[0][0];
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i==j)
                {
                    sum = sum + mat[i][j];
                    temp[i][j] = -1;
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=m-1;j>=0;j--)
            {
                if(i==n-j-1 && temp[i][j] != -1)
                {
                    sum = sum + mat[i][j];
                    temp[i][j] = -1;
                }
            }
        }
    return sum;
    }
};
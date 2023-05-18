class Solution {
public:
    int nCr(int n,int r)
    {
        long long res = 1;
        
        for(int i=0;i<r;i++)
        {
            res = res * (n-i);
            res = res / (i+1);
        }
    return res;
    }
    vector<int> getRow(int rowIndex) {
        vector<int> ans;
        
        for(int c=1;c<=rowIndex+1;c++)
        {
            int temp = nCr(rowIndex,c-1);
            ans.push_back(temp);
        }
      return ans; 
    }
};
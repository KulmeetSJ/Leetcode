class Solution {
public:
    double average(vector<int>& salary) {
     sort(salary.begin(),salary.end());
        
        int n = salary.size();
        double avg=0;
        int sum = 0;
        for(int i=1;i<n-1;i++)
        {
           sum = sum+salary[i];
        }
        avg = (double)sum/(n-2);
        
    return avg;
    }
};
class Solution {
public:
    int addDigits(int num) {
        if(num==0)
            return 0;
        
        int sum = 0;
        
        while(num!=0)
        {
            sum = sum+num%10;
            num/=10;
            if(num==0 && sum/10 !=0)
            {   
                
                num = sum;
                sum = 0;
            }
        }
    return sum;
    }
};
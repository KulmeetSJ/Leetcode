class Solution {
public:
    string getPermutation(int n, int k) {
        string ans = "";
        
        int fact = 1;
        for(int i=1;i<n;i++){
            fact *= i;
        }
        k--;
        
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            arr[i] = i+1;
        }
        
        while(true){
            ans = ans + to_string(arr[k/fact]);
            arr.erase(arr.begin() + k/fact);
            if(arr.empty()) break;
            k = k%fact;
            fact = fact/arr.size();
        }
    return ans;
    }
};
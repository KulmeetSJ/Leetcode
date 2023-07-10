class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        map<int,int> mp;
        
        for(int i=0;i<arr.size();i++){
            mp[arr[i]]++;
        }
        for(int i=0;i<target.size();i++){
            mp[target[i]]--;
        }
        for(auto i:mp){
            if(i.second>0) return false;
        }
        return true;
    }
};
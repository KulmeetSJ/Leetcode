class Solution {
public:
    bool rotateString(string s, string goal) {
        int len = s.length();
        if(len != goal.length()) return false;
        string temp= s+s;
        
        
            if(temp.find(goal) != string::npos)
                return true;
        
    return false;
    }
};
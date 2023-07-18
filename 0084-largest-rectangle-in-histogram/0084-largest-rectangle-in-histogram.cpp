class Solution {
public:
     void left(vector<int>& heights,vector<int>& leftSmaller,stack<int> &st){
        int n = heights.size();
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()] >= heights[i]) st.pop();            
            if(st.empty()) leftSmaller[i] = 0;
            else leftSmaller[i] = st.top() + 1;
            st.push(i);
        }
    }
    
    void right(vector<int>& heights,vector<int>& rightSmaller,stack<int> &st){
        int n = heights.size();
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && heights[st.top()] >= heights[i]) st.pop();            
            if(st.empty()) rightSmaller[i] = n-1;
            else rightSmaller[i] = st.top() - 1;
            st.push(i);
        }
    }
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> leftSmaller(n,-1);
        vector<int> rightSmaller(n,-1);
        
        stack<int> st;
        
        left(heights,leftSmaller,st);
        
        while(!st.empty()) st.pop();
        
        right(heights,rightSmaller,st);
                
        int maxArea = INT_MIN;
        
        for(int i=0;i<n;i++){
            int area = (rightSmaller[i]-leftSmaller[i]+1)*heights[i];
            maxArea = max(maxArea,area);
        }
    return maxArea;
    }
};
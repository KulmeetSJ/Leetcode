class Solution {
public:
   
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        int startingRow = 0 , endingRow = n-1 , startingCol = 0 , endingCol = m-1;
        
        
        int total_elements = n*m;
        int count =0;
        
        vector<int> ans;
        
        while(count<total_elements)
        {
            for(int index = startingCol;index <=endingCol && count<total_elements ;index++ )
            {
                ans.push_back(matrix[startingRow][index]);
                count++;
            }
            startingRow++;
            
            for(int index = startingRow;index <=endingRow && count<total_elements ;index++ )
            {
                ans.push_back(matrix[index][endingCol]);
                count++;
            }
            endingCol--;
            
            for(int index = endingCol;index >=startingCol && count<total_elements ;index-- )
            {
                ans.push_back(matrix[endingRow][index]);
                count++;
            }
            endingRow--;
            
            for(int index = endingRow;index >=startingRow && count<total_elements;index--)
            {
                ans.push_back(matrix[index][startingCol]);
                count++;
            }
            startingCol++;
            
        }
        
       
       
    return ans;
    }
};
//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends


class Solution
{   
    public:
    //Function to modify the matrix such that if a matrix cell matrix[i][j]
    //is 1 then all the cells in its ith row and jth column will become 1.
    void makeOnes(int row,int col,vector<vector<int> > &matrix,vector<vector<int> > &vis){
        int j = row-1;
        while(j>=0){
            if(matrix[j][col] != 1){
           matrix[j][col] = 1;
           vis[j][col] = 0;
        }
           j--;
        }
        j = row+1;
        while(j<matrix.size()){
            if(matrix[j][col] != 1){
            matrix[j][col] = 1;
            vis[j][col] = 0;
            }
            j++;
        }
        j = col-1;
        while(j>=0){
            if(matrix[row][j] != 1){
            matrix[row][j] = 1;
            vis[row][j] = 0;
            }
            j--;
        }
        j = col+1;
        while(j<matrix[0].size()){
            if(matrix[row][j] != 1){
            matrix[row][j] = 1;
            vis[row][j] = 0;
            }
            j++;
        }
    }
    void booleanMatrix(vector<vector<int> > &matrix)
    { 
        int n = matrix.size(),m = matrix[0].size();
        vector<vector<int>> vis(n,vector<int>(m,-1));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j] == 1 && vis[i][j] == -1){
                    makeOnes(i,j,matrix,vis);
                }
            }
        }
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    while(t--) 
    {
        int row, col;
        cin>> row>> col;
        vector<vector<int> > matrix(row); 
        for(int i=0; i<row; i++)
        {
            matrix[i].assign(col, 0);
            for( int j=0; j<col; j++)
            {
                cin>>matrix[i][j];
            }
        }
        
        Solution ob;
        ob.booleanMatrix(matrix);


        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                cout<<matrix[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}



// } Driver Code Ends
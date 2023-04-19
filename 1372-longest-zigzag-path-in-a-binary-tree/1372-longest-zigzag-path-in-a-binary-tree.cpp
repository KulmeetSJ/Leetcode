/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void solve(TreeNode* root,int dir,int currLen,int &maxLen)
    {
        if(!root) return;
        maxLen = max(maxLen,currLen);
        solve(root->left,0,dir?currLen+1:1,maxLen);
        solve(root->right,1,dir?1:currLen+1,maxLen);
        
    }
    int longestZigZag(TreeNode* root) {
        int maxLen = 0;
        solve(root,0,0,maxLen);
        solve(root,1,0,maxLen);
        
    return maxLen;        
    }
};
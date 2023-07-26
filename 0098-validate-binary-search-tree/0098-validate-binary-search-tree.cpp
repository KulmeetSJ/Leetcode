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
    bool solve(TreeNode* root,long int minVal, long int maxVal){
        if(!root) return true;
        
        if(root->val >= maxVal || root->val <= minVal) return false;
        
        return solve(root->left,minVal,root->val) 
            && solve(root->right,root->val,maxVal);
    }
    bool isValidBST(TreeNode* root) {
        if(!root->left && !root->right) return true;
        long int minVal = numeric_limits<long int>::min();
        long int maxVal = numeric_limits<long int>::max();
        return solve(root,minVal,maxVal);
    }
};
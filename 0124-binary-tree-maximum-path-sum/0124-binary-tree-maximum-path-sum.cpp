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
    int calcPathSum(TreeNode* root,int &maxi){
        if(root== NULL) return 0;
        
        //To avoid -ve values , we will check
        int lSum = max(0,calcPathSum(root->left,maxi));
        int rSum = max(0,calcPathSum(root->right,maxi));
        
        maxi = max(maxi , root->val + lSum + rSum);
        
        return root->val + max(lSum,rSum);
    }
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        int x = calcPathSum(root,maxi);
        
    return maxi;
    }
};
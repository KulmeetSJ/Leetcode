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
    void dfs(TreeNode* root,int mini,int maxi,int &diff){
        if(!root) return ;
        diff = max(diff,max(abs(mini-root->val),abs(maxi-root->val)));
        mini = min(mini,root->val);
        maxi = max(maxi,root->val);
        dfs(root->left,mini,maxi,diff);
        dfs(root->right,mini,maxi,diff);
        
    }
    int maxAncestorDiff(TreeNode* root) {
        if(!root) return 0;
        int maxi = root->val , mini = root->val , diff = 0;
        
        dfs(root,mini,maxi,diff);
        
        return diff;
    }
};
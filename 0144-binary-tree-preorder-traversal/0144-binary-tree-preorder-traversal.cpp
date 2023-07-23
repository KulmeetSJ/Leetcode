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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preorder;
        TreeNode* cur = root;
        while(cur!=NULL){
            if(cur->left == NULL){
                preorder.push_back(cur->val);
                cur = cur->right;
            }
            else{
                TreeNode* thread = cur->left;
                while(thread->right && thread->right != cur){
                    thread = thread->right;
                }
                if(thread->right == NULL){
                    thread->right = cur;
                    preorder.push_back(cur->val);
                    cur = cur->left;
                }
                else if(thread->right == cur){
                    thread->right = NULL;
                    cur = cur->right;
                }
            }
        }
    return preorder;
    }
};
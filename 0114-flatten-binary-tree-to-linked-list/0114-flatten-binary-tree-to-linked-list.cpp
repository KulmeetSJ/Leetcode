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
    void preorderTraversal(TreeNode* root, vector<int>& preorder){
        if(!root) return;
        
        preorder.push_back(root->val);
        preorderTraversal(root->left,preorder);
        preorderTraversal(root->right,preorder);
    }
    
    void iterate(TreeNode* root,vector<int> preorder){
        
        TreeNode* temp = root;
        for(int i=1;i<preorder.size();i++){
            TreeNode* temp = new TreeNode(preorder[i]) ;  
            root->right = temp;
        
            //root->right = new TreeNode(preorder[i]);
            root->left = NULL;
            root = root->right;
        }
    }
    
    void flatten(TreeNode* root) {
        if(!root) return;
        vector<int> preorder;
        preorderTraversal(root,preorder);
        
        root->left = NULL , root->right = NULL;
        
        iterate(root, preorder);
        
    }
    
    /*
    arr -> 1 2 3 4 5 6
         1
       2   5
      3 4    6
     
    node->left = NUll and node->right = 1 ...and move right
    and node->left = NUll and node->right = 2 
    
    */
};
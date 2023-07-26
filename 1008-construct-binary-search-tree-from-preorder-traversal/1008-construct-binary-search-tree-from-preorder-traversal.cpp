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
    TreeNode* solve(int &i,vector<int>& A,long int ub){
        if(i == A.size() || A[i] > ub ) return NULL;
        TreeNode *root = new TreeNode(A[i]);
        i++;
        root->left = solve(i,A,root->val);
        root->right = solve(i,A,ub);
        
    return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        long int upper_bound = numeric_limits<long int>::max();
        
        if(preorder.empty()) return NULL;
        int i=0;
        
        
    return solve(i,preorder,upper_bound);
    }
};
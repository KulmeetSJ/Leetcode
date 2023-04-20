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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        
        int max_width = 1;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        
        while(!q.empty())
        {
            int level_size = q.size();
            int start_index = q.front().second;
            int end_index = q.back().second;
            max_width = max(max_width , end_index - start_index+1);
            
            for(int i=0;i<level_size;i++)
            {
                pair<TreeNode*,int> p = q.front();
                TreeNode* temp = p.first;
                int node_index = p.second - start_index;
                q.pop();
                if(temp->left) q.push({temp->left,2LL * node_index+1});
                if(temp->right) q.push({temp->right,2LL * node_index+2});
            }
        }
    return max_width;
    }
};
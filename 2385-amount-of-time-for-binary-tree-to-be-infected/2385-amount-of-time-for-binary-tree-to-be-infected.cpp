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
    void convert(TreeNode* curr,int parent,unordered_map<int,set<int>>& mp){
        if(curr == NULL) return;
        
        if(mp.find(curr->val) == mp.end()){
            mp[curr->val] = set<int>();
        }
        
        set<int>& adjList = mp[curr->val];
        if(parent){
            adjList.insert(parent);
        }
        if(curr->left){
            adjList.insert(curr->left->val);
        }
        if(curr->right){
            adjList.insert(curr->right->val);
        }
        convert(curr->left,curr->val,mp);
        convert(curr->right,curr->val,mp);
    }
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int,set<int>> mp;
        convert(root,0,mp);
        
        queue<int> q;
        q.push(start);
        
        int minutes = 0;
        set<int> vis;
        vis.insert(start);
        
        
        while(!q.empty()){
            int sz = q.size();
            while(sz){
                int curr = q.front();
                q.pop();
                
                
                for(int num: mp[curr]){
                    if(vis.find(num) == vis.end()){
                        vis.insert(num);
                        q.push(num);
                    }
                }
                sz--;
            }
            minutes++;
        }
        return minutes-1;
    }
    
};
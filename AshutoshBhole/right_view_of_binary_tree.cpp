/*
    URL:https://leetcode.com/problems/binary-tree-right-side-view/
*/
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
    vector<int> rightSideView(TreeNode* root) {
        
        queue<TreeNode*> q;
        vector<int> op;
        
        if (root == NULL){
            return op;
        }
        
        q.push(root);
        
        while(!q.empty()){
            int i = 0;
            
            int nc = q.size();
            
            while(nc > 0) {
                TreeNode* node = q.front();
                q.pop();
                
                if(i==0){
                    op.push_back(node->val);
                    i++;
                }
                
                if(node->right != NULL) {
                    q.push(node->right);
                }
                if(node->left != NULL) {
                    q.push(node->left);
                }
                nc--;
            }
        }
        
        return op;
    }
};
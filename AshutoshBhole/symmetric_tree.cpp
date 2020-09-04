/*
    URL: https://leetcode.com/problems/symmetric-tree/submissions/
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
    
    
    bool isMirror(TreeNode* lnode, TreeNode* rnode) {
        
        if (lnode == NULL && rnode == NULL) {
            return true;
        } else if (lnode == NULL || rnode == NULL) {
            return false;
        }
        
        if (lnode-> val != rnode-> val) {
            return false;
        }
        
        bool val = isMirror(lnode->left, rnode->right);
        
        if (val == false) {
            return false;
        }
        val = isMirror(lnode->right, rnode->left);
        
        return val;
        
    }
    
    
    bool isSymmetric(TreeNode* root) {
        
        if (root == NULL) {
            return true;
        }
        
        if (root->left != NULL && root->right != NULL) {
            return isMirror(root->left, root->right);
        } else if (root->left == NULL && root->right == NULL){
            return true;
        }
        
        return false;
        
    }
};
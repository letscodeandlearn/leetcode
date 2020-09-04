/*
    URL: https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
    Status: Accepted
*/

#include<vector>
#include<queue>

using namespace std;
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> op;
        
        if (root == NULL) {
            return op;
        }
        
        bool ltr = true;
        queue<TreeNode*> myqueue;
        stack<int> mystack;
        
        myqueue.push(root);
        
        while(!myqueue.empty()) {
            
            int nc = myqueue.size();
            vector<int> tmpOp;
            while(nc > 0) {
                TreeNode* node = myqueue.front();
                myqueue.pop();
                
                if (ltr == true) {
                    tmpOp.push_back(node->val);
                } else {
                    mystack.push(node->val);
                }
                
                if(node->left != NULL) {
                    myqueue.push(node->left);
                }
                if(node->right != NULL) {
                    myqueue.push(node->right);
                }
                nc--;
            }
            
            if(ltr == false) {
                
                while(!mystack.empty()) {
                    int val = mystack.top();
                    mystack.pop();
                    tmpOp.push_back(val);
                }
            ltr = true;
            } else {
                ltr = false;
            }
            op.push_back(tmpOp);
        }
        
        return op;
    }
};

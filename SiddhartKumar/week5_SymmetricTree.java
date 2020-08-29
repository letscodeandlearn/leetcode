/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public boolean checkSymmetry(TreeNode left, TreeNode right) {
        if (left == null && right == null ) {
            return true;
        }
        
        if (left == null || right == null) return false;
        if (left.val == right.val) {
            boolean perm1 = this.checkSymmetry(left.left, right.right);
            boolean perm2 = this.checkSymmetry(left.right, right.left);
            
            if (perm1 && perm2) return true;
        }
        
        return false;
    }
    public boolean isSymmetric(TreeNode root) {
        return this.checkSymmetry(root, root);
    }
}
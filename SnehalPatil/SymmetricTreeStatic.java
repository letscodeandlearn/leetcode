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
    int[] traversedTree =  new int[7];
    int i = 0;
    public boolean isSymmetric(TreeNode root) {
        
        inOrderTravers(root);
        return isMirror(traversedTree);
        
    }
    public boolean isMirror(int[] arr) {
        int frontPtr = 0;
        int backPtr = arr.length - 1;
        if (frontPtr <= backPtr && arr[frontPtr] == arr[backPtr]) {
            frontPtr++;
            backPtr--;
        } else {
            return false;
        }
        return true;
    }
    public void inOrderTravers(TreeNode root) {
        if (root == null) {
            return;
        }
        inOrderTravers(root.left);
        traversedTree[i] = root.val;
        i++;
        inOrderTravers(root.right);

    }
}
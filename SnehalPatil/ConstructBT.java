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

 /* wrong output, need to fix this
 Input
[1,2]
[2,1]
Output
[1,null,2]
Expected
[1,2]
 */
class Solution {
    int preIndex = 0;
    public TreeNode buildTree(int[] preorder, int[] inorder) {
        return build(preorder, inorder, 0, inorder.length - 1);
    }
    
    public TreeNode build(int[] pre, int[] in, int inStart, int inEnd) {
        if(preIndex > pre.length || inStart > inEnd) {
            return null;
        }
        
        TreeNode tree = new TreeNode(pre[preIndex++]);
        
        if(inStart == inEnd) {
            return tree;
        }
       
        int foundIn = searchInorder(in, inStart, inEnd, tree.val);
        
        tree.left = build(pre, in, inStart, foundIn - 1);
        tree.right = build(pre, in, foundIn + 1, inEnd);
        
        return tree;
    }
    
    public int searchInorder(int[] in, int start, int end, int val) {
        int index = 0;
        
        for (int i = start; i < end; i++) {
            if (in[i] == val) {
                return i;
            }
        }
        
        return index;
    }
}
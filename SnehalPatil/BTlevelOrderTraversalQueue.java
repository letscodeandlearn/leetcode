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
    
    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> levelorder = new ArrayList<>();
        
        Queue<TreeNode> q = new LinkedList();
        if (root == null) {
            return levelorder;
        }
        q.add(root);
        
        while(!q.isEmpty()) {
            int size = q.size();
            List<Integer> currentList = new ArrayList<>();
            for(int i=0; i < size; i++) {
                root = q.remove();
                
                currentList.add(root.val);
                if (root.left != null) {
                    q.add(root.left);
                }
                if (root.right != null) {
                    q.add(root.right);
                }
            }
            levelorder.add(currentList);
        }
        
        return levelorder;
    
    }
}
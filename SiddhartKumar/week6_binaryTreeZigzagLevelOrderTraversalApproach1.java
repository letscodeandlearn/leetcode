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
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        Queue <TreeNode> q = new LinkedList<TreeNode>();
        boolean leftToRight = true;
        List<List<Integer>> result = new ArrayList<List<Integer>>();
        if (root == null) {
            
            return result;
        }
        
        Stack <TreeNode> s = new Stack<>();
        TreeNode node = null;
        q.add(root);
        while (!q.isEmpty()) {
            List<Integer> levelList = new ArrayList<>();
            s.clear();
            int size = q.size();
            for (int i = 0; i < size; i++) {
                node = q.remove();
                levelList.add(node.val);
                if (leftToRight) {
                    if (node.left != null) s.add(node.left);
                    if (node.right != null) s.add(node.right);
                } else {
                    if (node.right != null) s.add(node.right);
                    if (node.left != null) s.add(node.left);
                }

            }
            leftToRight = !leftToRight;
            result.add(levelList);
            while(!s.isEmpty()) {
                q.add(s.pop());
            }
        }
        return result;
    }
}
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
        List<List<Integer>> result = new ArrayList<List<Integer>>();
        if (root == null) return result;
        
        LinkedList <TreeNode> q = new LinkedList<TreeNode>();
        boolean leftToRight = true;
        TreeNode node = null;
        
        q.add(root);
        while (!q.isEmpty()) {
            List<Integer> levelList = new ArrayList<>();
            int size = q.size();
            for (int i = 0; i < size; i++) {
                if (leftToRight) {
                    node = q.removeFirst();
                    if (node.left != null) q.addLast(node.left);
                    if (node.right != null) q.addLast(node.right);
                } else {
                    node = q.removeLast();
                    if (node.right != null) q.addFirst(node.right);
                    if (node.left != null) q.addFirst(node.left);
                }
                levelList.add(node.val);
            }
            leftToRight = !leftToRight;
            result.add(levelList);

        }
        return result;
    }
}
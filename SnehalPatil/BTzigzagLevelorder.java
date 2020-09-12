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
        List<List<Integer>> zigzag = new ArrayList<>();
        Stack<TreeNode> stack = new Stack<>();
        Queue<TreeNode> queue = new LinkedList<>();
        
        boolean leftright = true;
        
        if (root == null) {
            return zigzag;
        }
        
        queue.add(root);
        
        while(!queue.isEmpty()) {
            int size = queue.size();
            List<Integer> list = new ArrayList<>();
            for(int i=0; i < size; i++) {
                root = queue.remove();
                list.add(root.val);
                if(leftright) {
                    if(root.left != null) stack.add(root.left);
                    if(root.right != null) stack.add(root.right);
                } else {
                    if(root.right != null) stack.add(root.right);
                    if(root.left != null) stack.add(root.left);
                }
                
            }
            leftright = !leftright;
            zigzag.add(list);
            while(!stack.empty()) {
                queue.add(stack.pop());
            }
            
        }
        
        return zigzag;
        
        
        
    }
}
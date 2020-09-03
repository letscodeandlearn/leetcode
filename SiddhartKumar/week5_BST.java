// "static void main" must be defined in a public class.
public class Main {
    
    public static class TreeNode {
        public int val;
        public TreeNode left = null;
        public TreeNode right = null;
        public TreeNode parent = null;
        
        public TreeNode(int val) {
            this.val = val;
        }
    }
    public static class BinarySearchTree {
        public TreeNode root;
        
        public void insert(int val) {
            if (this.root == null) {
                root = new TreeNode(val);
                System.out.println("Value " + val + " inserted");
                return;
            }
            TreeNode parent = null;
            TreeNode node = this.root;
            
            while(node != null) {
                parent = node;
                if (val < node.val) {
                    node = node.left;
                }
                else {
                    node = node.right;
                }
            }
            TreeNode newNode = new TreeNode(val);
            newNode.parent = parent;
            if (parent.val > val) {
                parent.left = newNode;
            } else {
                parent.right = newNode;
            }
            System.out.println("Value " + val + " inserted");
        }
        
        public void Ampute(TreeNode n, TreeNode s) {
        	if(n.parent == null) this.root = s;
        	else if (n.parent.left == n) n.parent.left = s;
        	else if (n.parent.right == n) n.parent.right = s;
        	if (s != null) s.parent = n.parent;
        }
        
        public void delete(int val) {
            TreeNode node = this.search(val);
            
            if (node == null) return;
            
            if (node.left == null && node.right == null) {
            	this.Ampute(node,null);
            } else if (node.right == null) {
            	this.Ampute(node, node.left);
            } else if (node.left == null) {
                this.Ampute(node, node.right);
            } else {
                TreeNode successor = this.minimum(node.right);
                if (successor != node.right) {
            
                	
                	this.Ampute(successor, successor.right);
                	successor.right = node.right;
                	successor.right.parent = successor;
                }
                this.Ampute(node, successor);
               	successor.left = node.left;
                successor.left.parent = successor;   
          
            }
        }
        
        public TreeNode search(int searchVal) {
            TreeNode node = this.root;
            
            while (node != null) {
                if (node.val == searchVal) return node;
                
                if (searchVal < node.val) {
                    node = node.left;
                } else node = node.right;
            }
            return null;
        }
        
        public TreeNode minimum(TreeNode node) {
            while(node.left != null) {
                node = node.left;
            }
            return node;
        }
        
        public void printTree(TreeNode node) {
            if (node == null) return;
            
            this.printTree(node.left);
            System.out.println(node.val);
            this.printTree(node.right);
        }
        
    }
    public static void main(String[] args) {
        BinarySearchTree bst = new BinarySearchTree();
        bst.insert(12);
        bst.insert(5);
        bst.insert(2);
        bst.insert(9);
        bst.insert(18);
        bst.insert(15);
        bst.insert(13);
        bst.insert(17);
        bst.insert(19);
        System.out.println("BST:");
        bst.printTree(bst.root);
        
        bst.delete(12);
        System.out.println("BST:");
        bst.printTree(bst.root);
        
    }
}
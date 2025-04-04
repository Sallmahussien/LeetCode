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
    public TreeNode lcaDeepestLeaves(TreeNode root) {
        List<TreeNode> deepestNodes = getDeepestNodes(root);
        Set<TreeNode> targetSet = new HashSet<>(deepestNodes);

        return getLCA(root, targetSet);   
    }

    private List<TreeNode> getDeepestNodes(TreeNode root) {
        Queue<TreeNode> queue = new LinkedList<>();
        queue.add(root);
        List<TreeNode> level = new ArrayList<>();

        while(!queue.isEmpty()) {
            int size = queue.size();
            level = new ArrayList<>();

            for (int i = 0; i < size; i++) {
                TreeNode head = queue.poll();
                level.add(head);

                if (head.left != null) queue.add(head.left);
                if (head.right != null) queue.add(head.right);
            }
        }

        return level;
    }

    private TreeNode getLCA(TreeNode root, Set<TreeNode> target) {
        if (root == null || target.contains(root)) return root;

        TreeNode left = getLCA(root.left, target);
        TreeNode right = getLCA(root.right, target);

        if (left != null && right != null) return root;
        return left != null ? left : right;
    }
}
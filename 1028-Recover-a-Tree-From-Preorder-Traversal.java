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
    public TreeNode recoverFromPreorder(String traversal) {
        Stack<TreeNode> stk = new Stack<>();
        int idx = 0, n = traversal.length(), depth = 0;

        while (idx < n) {
            depth = 0;

            while (idx < n && traversal.charAt(idx) == '-') {
                idx++;
                depth++;
            }

            int startIdx = idx;
            while (idx < n && traversal.charAt(idx) != '-') {
                idx++;
            }
            
            int val = Integer.parseInt(traversal.substring(startIdx, idx));
            TreeNode node = new TreeNode(val);

            while (stk.size() > depth) {
                stk.pop();
            }

            if (!stk.isEmpty()) {
                TreeNode parent = stk.peek();

                if (parent.left == null) {
                    parent.left = node;
                } else {
                    parent.right = node;
                }
            }

            stk.push(node);
        }

        while (stk.size() > 1) {
            stk.pop();
        }

        return stk.peek();
    }
}
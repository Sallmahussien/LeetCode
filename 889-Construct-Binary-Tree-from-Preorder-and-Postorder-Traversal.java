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
    public TreeNode constructFromPrePost(int[] preorder, int[] postorder) {
        Map<Integer, Integer> postorderMap = new HashMap<>();
        int n = postorder.length;

        for (int i = 0; i < n; i++) {
            postorderMap.put(postorder[i], i);
        }

        Map<Integer, TreeNode> valToNode = new HashMap<>();

        TreeNode root = new TreeNode(preorder[0]);
        valToNode.put(preorder[0], root);

        for (int i = 0; i < n-1; i++) {
            int parentVal = preorder[i];
            TreeNode parentNode = valToNode.get(parentVal);

            if (!valToNode.containsKey(preorder[i+1])) {
                parentNode.left = new TreeNode(preorder[i+1]);
                valToNode.put(preorder[i+1], parentNode.left);
            }

            int rightIdx = postorderMap.get(parentVal) - 1;
            if (rightIdx >= 0 && !valToNode.containsKey(postorder[rightIdx])) {
                parentNode.right = new TreeNode(postorder[rightIdx]);
                valToNode.put(postorder[rightIdx], parentNode.right);
            }
        }

        return root;
    }
}
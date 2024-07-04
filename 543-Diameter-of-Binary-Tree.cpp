/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    int count_nodes(TreeNode* root) {
        if (!root) return 0;

        return 1 + max(count_nodes(root->left), count_nodes(root->right));
    }

    int height(TreeNode* node, int& diameter) {
        if (!node) return -1;

        int leftHeight = height(node->left, diameter);
        int rightHeight = height(node->right, diameter);

        diameter = max(diameter, leftHeight + rightHeight + 2);

        return 1 + max(leftHeight, rightHeight);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;

        height(root, diameter);

        return diameter;
    }
};
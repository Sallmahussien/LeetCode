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
    bool is_symm(TreeNode* left, TreeNode* right) {
        if (!left && !right) return true;
        if ((!left && right) || (left && !right)) return false;

        if (left->val != right->val) return false;

        return is_symm(left->left, right->right) && is_symm(left->right, right->left);
    }
public:
    bool isSymmetric(TreeNode* root) {
        return is_symm(root->left, root->right);
    }
};
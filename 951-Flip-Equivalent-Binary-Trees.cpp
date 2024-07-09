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
    bool isFlipEquiv(TreeNode* root1, TreeNode* root2) {
        if (!root1 && !root2) return true;
        if (!root1 || !root2) return false;
        if (root1->val != root2->val) return false;

        return (isFlipEquiv(root1->left, root2->left) && isFlipEquiv(root1->right, root2->right)) || (isFlipEquiv(root1->left, root2->right) && isFlipEquiv(root1->right, root2->left)); 
    }
public:
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        return isFlipEquiv(root1, root2);   
    }
};
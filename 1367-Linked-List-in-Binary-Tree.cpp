/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    bool checkPath(ListNode* head, TreeNode* node) {
        if (!head) return true;
        if (!node) return false;

        if (head->val == node->val) {
            return checkPath(head->next, node->left) || checkPath(head->next, node->right);
        }

        return false;
    }

public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        if (!root) return false;

        return checkPath(head, root) || isSubPath(head, root->left) || isSubPath(head, root->right);
    }
};

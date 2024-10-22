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
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        queue<TreeNode*> q;
        q.push(root);
        vector<long long> levels_sum;

        while (!q.empty()) {
            int sz = q.size();

            long long sum = 0;
            while (sz--) {
                TreeNode* curr_node = q.front();
                q.pop();

                if (curr_node->left) q.push(curr_node->left);
                if (curr_node->right) q.push(curr_node->right);

                sum += curr_node->val;
            }

            levels_sum.push_back(sum);
        }

        sort(levels_sum.begin(), levels_sum.end(), greater<long long>());
        return levels_sum.size() < k ? -1 : levels_sum[k-1];
    }
};
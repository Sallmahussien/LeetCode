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
    TreeNode* replaceValueInTree(TreeNode* root) {
        if (!root) return nullptr;
    
        queue<TreeNode*> q;
        q.push(root);

        vector<int> levels_sum;

        while (!q.empty()) {
            int sz = q.size();
            int sum = 0;
            
            while (sz--) {
                TreeNode* curr = q.front();
                q.pop();
                
                sum += curr->val;
    
                if (curr->left) {
                    q.push(curr->left);
                }

                if (curr->right){
                    q.push(curr->right);
                }
            }
            levels_sum.push_back(sum);
        }

        q.push(root);
        root->val = 0;
        int level = 1;

        while (!q.empty()) {
            int sz = q.size();

            while (sz--) {
                TreeNode* curr = q.front();
                q.pop();

                int siblings_sum =
                    (curr->left ? curr->left->val : 0) +
                    (curr->right ? curr->right->val : 0);

                if (curr->left) {
                    q.push(curr->left);
                    curr->left->val = levels_sum[level] - siblings_sum;
                }

                if (curr->right) {
                    q.push(curr->right);
                    curr->right->val = levels_sum[level] - siblings_sum;
                }
            }

            level++;
        }
        
        return root;
    }
};

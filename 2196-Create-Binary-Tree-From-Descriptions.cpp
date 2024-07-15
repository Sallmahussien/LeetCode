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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> nodes;
        unordered_set<int> children;

        for (auto description : descriptions) {
            int parent = description[0];
            int child = description[1];
            bool isLeft = description[2];

            children.insert(child);

            if (!nodes.count(parent)) nodes[parent] = new TreeNode(parent);

            if (!nodes.count(child)) nodes[child] = new TreeNode(child);

            if (isLeft) nodes[parent]->left = nodes[child];
            else nodes[parent]->right = nodes[child];
        }

        TreeNode* root;
        for (auto description : descriptions) {
            if (!children.count(description[0])) {
                root = nodes[description[0]];
                break;
            }
        }

        return root;
    }
};
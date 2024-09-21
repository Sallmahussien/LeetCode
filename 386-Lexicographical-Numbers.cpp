class Solution {
private:
    void dfs(vector<int>& res, int root, int n) {
        if (root > n) return;

        res.push_back(root);

        for (int i = 0; i <= 9; i++) {
            int child = root * 10 + i;
            if (child > n) break;
            dfs(res, child, n);
        }
    }

public:
    vector<int> lexicalOrder(int n) {
        vector<int> res;

        for (int i = 1; i <= 9; i++) {
            dfs(res, i, n);
        }
        return res;
    }
};
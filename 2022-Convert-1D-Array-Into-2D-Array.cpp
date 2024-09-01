class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>> res;
        if (n * m != original.size()) return res;

        for  (int i = 0; i < m; i++) {
            vector<int> sub;
            for (int j = i * n; j < (i+1) * n; j++) {
                sub.push_back(original[j]);
            }

            res.push_back(sub);
        }

        return res;        
    }
};
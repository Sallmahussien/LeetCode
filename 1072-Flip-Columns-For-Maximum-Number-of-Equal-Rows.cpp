class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<string, int> row_count;

        for (vector<int>& row : matrix) {

            string row_str = "";
            bool flip = row[0];

            // convert each row to str
            for (int c : row) {
                row_str += (flip ? 1 - c : c) + '0';
            }

            row_count[row_str]++;
        }

        int res = 0;

        for (auto& pair: row_count) {
            res = max(res, pair.second);
        }

        return res;
    }
};
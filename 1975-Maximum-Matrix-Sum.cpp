class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long sum = 0;
        int min_num = INT_MAX;
        int neg_count = 0;

        for (vector<int>& row : matrix) {
            for (int i = 0; i < row.size(); i++) {
                sum += abs(row[i]);
                if (row[i] < 0) neg_count++;
                min_num = min(min_num, abs(row[i]));
            }
        }

        // check if the negative count is odd
        if (neg_count % 2 == 1) {
            sum -= (2* abs(min_num));
        }

        return sum;
    }
};
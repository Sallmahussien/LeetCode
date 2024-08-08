class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int r = matrix.size(), c = matrix[0].size();
        int top = 0, bottom = r - 1, right = c - 1, left = 0;

        while (top <= bottom && left <= right) {
            for (int j = left; j <= right; j++) {
                res.push_back(matrix[top][j]);
            }
            top++;

            for (int i = top; i <= bottom; i++) {
                res.push_back(matrix[i][right]);
            }
            right--;
 
            for (int j = right; top <= bottom && j >= left; j--) {
                res.push_back(matrix[bottom][j]);
            }
            bottom--;

            for (int i = bottom; left <= right && i >= top; i--) {
                res.push_back(matrix[i][left]);
            }
            left++;
        }

        return res;
    }
};
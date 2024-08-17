class Solution {
private:
    long long calculateScore(const vector<vector<int>>& points, const vector<int>& path) {
        long long score = points[0][path[0]];
        int m = path.size();
        for (int r = 1; r < m; ++r) {
            score += points[r][path[r]];
            score -= abs(path[r] - path[r - 1]);
        }
        return score;
    }

     void generatePaths(const vector<vector<int>>& points, int row, vector<int>& currentPath, long long& maxScore) {
        int n = points[0].size();
        int m = points.size();

        if (row == m) {
            long long score = calculateScore(points, currentPath);
            maxScore = max(maxScore, score);
            return;
        }

        for (int c = 0; c < n; ++c) {
            currentPath[row] = c;
            generatePaths(points, row + 1, currentPath, maxScore);
        }
    }
public:
    long long maxPoints(vector<vector<int>>& points) {
        int m = points.size();
        int n = points[0].size();
        
        // DP array to store maximum points for each cell in the current row
        vector<long long> prevRow(points[0].begin(), points[0].end());
        
        // Iterate over each row starting from the second row
        for (int r = 1; r < m; ++r) {
            vector<long long> leftMax(n), rightMax(n);
            
            // Compute leftMax: maximum score we can obtain from the left side
            leftMax[0] = prevRow[0];
            for (int c = 1; c < n; ++c) {
                leftMax[c] = max(leftMax[c - 1], prevRow[c] + c);
            }
            
            // Compute rightMax: maximum score we can obtain from the right side
            rightMax[n - 1] = prevRow[n - 1] - (n - 1);
            for (int c = n - 2; c >= 0; --c) {
                rightMax[c] = max(rightMax[c + 1], prevRow[c] - c);
            }
            
            // Update the current row dp values using leftMax and rightMax
            vector<long long> currRow(n);
            for (int c = 0; c < n; ++c) {
                currRow[c] = points[r][c] + max(leftMax[c] - c, rightMax[c] + c);
            }
            
            // Move to the next row
            prevRow = currRow;
        }
        
        // The answer will be the maximum value in the last row
        return *max_element(prevRow.begin(), prevRow.end());
    }
};
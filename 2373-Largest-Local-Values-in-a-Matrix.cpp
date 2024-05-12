class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> res(n-2, vector<int>(n-2));

        
        for (int r = 0; r < n-2; r++) {
            for (int c = 0; c < n-2; c++) {
                int max = INT_MIN;
                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        if (grid[i+r][j+c] > max) max = grid[i+r][j+c];
                    }
                }

                res[r][c] = max;
            }
        }

        return res;
    }
};
class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        vector<vector<int>> res;
        int outputSize = rows * cols;
        int steps = 1;
        int r = rStart, c = cStart;
        int idx = 0;

        res.push_back({r, c});

        while (res.size() < outputSize) {
            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < steps; j++) {
                    r += directions[idx][0];
                    c += directions[idx][1];

                    if (r >= 0 && r < rows && c >= 0 && c < cols) {
                        res.push_back({r, c});
                    }
                }

                idx = (idx + 1) % 4;
            }

            steps++;
        }

        return res;
    }
};
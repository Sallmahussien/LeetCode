class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int ROW = matrix.size();
        int COL = matrix[0].size();
        vector<vector<int>> memo(ROW, vector<int>(COL, -1));

        function<int(int, int)> dfs = [&](int r, int c) -> int{
            if (r == ROW || c == COL || matrix[r][c] == 0) {
                return 0;
            }

            if (memo[r][c] != -1) return memo[r][c];

            memo[r][c] = 1 + min(
                dfs(r+1, c), // down
                min (
                    dfs(r+1, c+1), // diagonal
                    dfs(r, c+1) // right
                ) 
            );

            return memo[r][c];
        };

        int res = 0;
        for (int i = 0; i < ROW; i++) {
            for (int j = 0; j < COL; j++) {
                res += dfs(i, j);
            }
        }

        return res;
    }
};
class Solution {
private:
    void dfs(int r, int c, set<pair<int, int>>& visited, vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        if (r < 0 || c < 0 || r == row || c == col || grid[r][c] == 0 || visited.count({r, c})) return;

        visited.insert({r, c});
        vector<pair<int, int>> neighbors = {
            {r+1, c}, {r, c+1},
            {r-1, c}, {r, c-1},
        };

        for (auto coord : neighbors) {
            dfs(coord.first, coord.second, visited, grid);
        }
    }

public:
    int minDays(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();

        set<pair<int, int>> visited;
        int count = 0;

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] && !visited.count({i, j})) {
                    dfs(i, j, visited, grid);
                    count++;
                }

            }
        }

        if (count != 1) return 0;

        vector<pair<int, int>> land(visited.begin(), visited.end());
        for (auto coord : land) {
            grid[coord.first][coord.second] = 0;

            set<pair<int, int>> visited;
            int count = 0;
            for (int i = 0; i < r; i++) {
                for (int j = 0; j < c; j++) {
                    if (grid[i][j] && !visited.count({i, j})) {
                        dfs(i, j, visited, grid);
                        count++;
                    }

                }
            }

            if (count != 1) return 1;

            grid[coord.first][coord.second] = 1;
        }

        return 2;
    }
};
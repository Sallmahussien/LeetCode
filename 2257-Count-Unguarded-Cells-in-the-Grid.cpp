class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<char>> grid(m, vector<char>(n, '\0'));

        // loop through walls grid to fill our walls
        for (vector<int>& wall : walls) {
            int r = wall[0];
            int c = wall[1];
            grid[r][c] = 'W';
        }

        // loop through guards grid to fill our guards
        for (vector<int>& guard : guards) {
            int r = guard[0];
            int c = guard[1];
            grid[r][c] = 'G';
        }

        for (vector<int>& guard : guards) {
            int r = guard[0];
            int c = guard[1];

             // fill the top
            int new_r = r - 1;
            while (new_r >= 0 && grid[new_r][c] != 'W' && grid[new_r][c] != 'G') {
                grid[new_r][c] = 'X';
                new_r--;
            }

            // fill the bottom
            new_r = r + 1;
            while (new_r < m && grid[new_r][c] != 'W' && grid[new_r][c] != 'G') {
                grid[new_r][c] = 'X';
                new_r++;
            }

            // fill the right
            int new_c = c + 1;
            while (new_c < n && grid[r][new_c] != 'W' && grid[r][new_c] != 'G') {
                grid[r][new_c] = 'X';
                new_c++;
            }

            // fill the left
            new_c = c - 1;
            while (new_c >= 0 && grid[r][new_c] != 'W' && grid[r][new_c] != 'G') {
                grid[r][new_c] = 'X';
                new_c--;
            }
        }

        int count = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '\0') count++;
            }
        }

        return count;   
    }
};
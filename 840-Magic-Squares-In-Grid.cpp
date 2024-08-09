class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int res = 0;
        int r = grid.size();
        int c = grid[0].size();

        for (int i = 0; i < r - 2; i++) {
            for (int j = 0; j < c - 2; j++) {

                // start of each sub grid, i want to calculate:
                // sum of three rows
                // sum of three columns
                // sum of two diagonals

                bool is_magic = true;

                unordered_set<int> unique_nums;
                for (int rr = i; rr < i + 3; rr++) {
                    for (int cc = j; cc < j + 3; cc++) {
                        if (unique_nums.count(grid[rr][cc]) || grid[rr][cc] > 9 || grid[rr][cc] < 1) {
                            is_magic = false;
                            break;
                        }

                        unique_nums.insert(grid[rr][cc]);
                    }
                }

                if (!is_magic) continue;
                
                int left_diag = grid[i][j] + grid[i+1][j+1] + grid[i+2][j+2];
                int right_diag = grid[i][j+2] + grid[i+1][j+1] + grid[i+2][j];
                if (left_diag != right_diag) continue;
                

                // row sum
                for (int rr = i; rr < i + 3; rr++) {
                    int row_sum = 0;
                    for (int cc = j; cc < j + 3; cc++) {
                        row_sum += grid[rr][cc];
                    }

                    if (row_sum != left_diag) {
                        is_magic = false;
                        break;
                    }
                }

                if (!is_magic) continue;

                // column sum
                for (int cc = j; cc < j + 3; cc++) {
                    int col_sum = 0;

                    for (int rr = i; rr < i + 3; rr++) {
                        col_sum += grid[rr][cc];
                    }

                    if (col_sum != left_diag) {
                        is_magic = false;
                        break;
                    }
                }

                if (!is_magic) continue;

                res++;
            }
        }

        return res;
    }
};
class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        int r = grid.size(), c = grid[0].size();
        vector<vector<int>> moves(r, vector<int>(c, 0));
        vector<int> directions = {-1, 0, 1};

        for (int j = c-2; j >= 0; j--) {
            for (int i = 0; i < r; i++) {
                int move = 0;
                
                for (int direction: directions) {
                    int ROW = i + direction;
                    if (ROW >= 0 && ROW < r) {
                        if (grid[i][j] < grid[ROW][j+1]) {
                            move = max(move, 1 + moves[ROW][j+1]);
                        }
                    }
                }

                moves[i][j] = move;
            }
        }

        int res = 0;
        for (int i = 0; i < r; i++) {
            res = max(res, moves[i][0]);
        }

        return res;       
    }
};
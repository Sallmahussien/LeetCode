class Solution {
private:
    void print(vector<vector<int>>& grid) {
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                cout << grid[i][j] << " ";
            }

            cout << endl;
        }
    }
public:
    int matrixScore(vector<vector<int>>& grid) {
        for (int i = 0; i < grid.size(); i++) {
            if (grid[i][0] == 0) {
                for (int j = 0; j < grid[i].size(); j++) {
                    grid[i][j] = !grid[i][j];
                }
            }
        }

        for (int j = 1; j < grid[0].size(); j++) {
            int zeros = 0, ones = 0;
            for (int i = 0; i < grid.size(); i++) {
                if (grid[i][j] == 0) zeros++;
                else ones++;
            }

            if (zeros > ones) {
                for (int i = 0; i < grid.size(); i++) {
                    grid[i][j] = !grid[i][j];
                }
            }
        }

        int res = 0;

        for (int i = 0; i < grid.size(); i++) {
            int decimal = 0;
            for (int j = 0; j < grid[i].size(); j++) {
                decimal = decimal << 1 | grid[i][j];
            }

            res += decimal;
        }

        return res;
    }
};
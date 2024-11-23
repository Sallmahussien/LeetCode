class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m = box.size();
        int n = box[0].size();

        // move each stone to the right
        for (vector<char>& row : box) {
            for (int i = n-2; i >=0; i--) {
                int idx = i;
                while (idx <= n-2 && row[idx] == '#' && row[idx+1] == '.') {
                    row[idx+1] = row[idx];
                    row[idx] = '.';
                    idx++;
                }
            }
        }

        vector<vector<char>> res(n, vector<char>(m));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                res[j][m-i-1] = box[i][j];
            }
        }

        return res;
    }
};
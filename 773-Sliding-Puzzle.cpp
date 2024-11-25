class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        vector<vector<int>> directions = {
            {1, 3},
            {0, 2, 4},
            {1, 5},
            {0, 4},
            {1, 3, 5},
            {2, 4}
        };

        string board_str = "";
        for (vector<int> & row : board) {
            for (int c : row) {
               board_str += to_string(c); 
            }
        }

        queue<string> q;
        q.push(board_str);

        unordered_set<string> visited;
        visited.insert(board_str);

        int res = 0;

        while (!q.empty()) {
            int size = q.size();

            while (size--) {
                string str = q.front();
                q.pop();

                if (str == "123450") return res;

                int empty_idx = str.find('0');
                for (int dir : directions[empty_idx]) {
                    string new_str = str;
                    swap(new_str[empty_idx], new_str[dir]);

                    if (visited.count(new_str)) continue;

                    q.push(new_str);
                    visited.insert(new_str);
                }
            }

            res++;
        }

        return -1;
    }
};
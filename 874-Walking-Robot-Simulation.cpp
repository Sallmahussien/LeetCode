class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int dist = 0;
        int x = 0, y = 0;
        int dir_idx = 0;
        vector<vector<int>> directions = {
            {0, 1},
            {1, 0},
            {0, -1},
            {-1, 0}
        };

        unordered_set<string> obstacle_set;
        for (const auto& obs : obstacles) {
            obstacle_set.insert(to_string(obs[0]) + "," + to_string(obs[1]));
        }

        for (int command : commands) {
            if (command == -1) {
                // r
                dir_idx = (dir_idx + 1) % 4;
            } else if (command == -2) {
                // l
                dir_idx = (dir_idx + 3) % 4;
            } else {
                for (int i = 0; i < command; i++) {
                    int next_x = x + directions[dir_idx][0];
                    int next_y = y + directions[dir_idx][1];

                    string coor_str = to_string(next_x) + "," + to_string(next_y);
                    if (obstacle_set.count(coor_str)) break;

                    x = next_x;
                    y = next_y;
                }

                dist = max(dist, (x * x) + (y * y));

            }
        }

        return dist;
    }
};
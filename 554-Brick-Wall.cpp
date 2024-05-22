class Solution {
private:
    int get_max(unordered_map<int, int>& brick_crosses) {
        int max = INT_MIN;

        for (auto& pair: brick_crosses) {
            if (pair.second > max) max = pair.second;
        }

        return max;
    }

    int sum(vector<int>& nums) {
        int sum = 0;

        for (int num: nums) sum += num;

        return sum;
    }
public:
    int leastBricks(vector<vector<int>>& wall) {
        // brute force solution, it results memory limit exceeded
        // int wall_width = sum(wall[0]);

        // unordered_map<int, int> brick_crosses;

        // for (int i = 1; i < wall_width; i++) brick_crosses[i] = 0;

        // for (int i = 0; i < wall.size(); i++) {
        //     int width = 0;
        //     int idx = 0;
        //     for (int j = 1; j < wall_width; j++) {
        //         if (wall[i][idx] + width == j) {
        //             width += wall[i][idx];
        //             idx++;
        //         } else brick_crosses[j]++;
        //     }
        // }

        // return brick_crosses.empty() ? 0 :  get_min(brick_crosses); 

        unordered_map<int, int> gaps;
        int max_gaps = INT_MIN;

        for (int i = 0; i < wall.size(); i++) {
            int width = 0;
            for (int j = 0; j < wall[i].size()-1; j++) {
                width += wall[i][j];
                gaps[width]++;
                max_gaps = max(max_gaps, gaps[width]);
            }
        }

        return gaps.empty() ? wall.size() : wall.size() - max_gaps;
    }
};
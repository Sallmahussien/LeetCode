class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int max_num = arrays[0].back(), min_num = arrays[0][0];
        int dist = 0;

        for (int i = 1; i < arrays.size(); i++) {
            int sub_max = arrays[i].back(), sub_min = arrays[i][0];

            dist = max(dist, max(abs(max_num - sub_min), abs(sub_max - min_num)));

            max_num = max(max_num, sub_max);
            min_num = min(min_num, sub_min);
        }

        return dist;
    }
};
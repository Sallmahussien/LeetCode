class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        if (arr.empty()) return {};

        vector<int> sorted_arr = arr;
        sort(sorted_arr.begin(), sorted_arr.end());

        unordered_map<int, int> rank_map;
        int rank = 1;

        for (int n : sorted_arr) {
            if (!rank_map.count(n)) {
                rank_map[n] = rank++;
            }
        }

        vector<int> result(arr.size());
        for (int i = 0; i < arr.size(); ++i) {
            result[i] = rank_map[arr[i]];
        }

        return result;
    }
};

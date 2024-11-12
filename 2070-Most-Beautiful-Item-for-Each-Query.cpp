class Solution {
private:
    static bool is_greater(vector<int>& a, vector<int>& b) {
        return a[0] < b[0];
    }

public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        vector<pair<int, int>> query_with_idx;
        for (int i = 0; i < queries.size(); i++) {
            query_with_idx.push_back({queries[i], i});
        }

        sort(query_with_idx.begin(), query_with_idx.end());
        sort(items.begin(), items.end(), is_greater);
        int max_beauty = 0;
        int idx = 0;
        vector<int> res(queries.size());

        for (const auto& [q, original_idx] : query_with_idx) {
            while (idx < items.size() && items[idx][0] <= q) {
                max_beauty = max(max_beauty, items[idx][1]);
                idx++;
            }
            
            res[original_idx] = max_beauty;
        }

        return res;
    }
};
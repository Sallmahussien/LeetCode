class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k = nums.size();

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;

        for (int i = 0; i < k; i++) {
            for (int j = 0; j < nums[i].size(); j++) {
                min_heap.push({nums[i][j], i});
            }
        }

        vector<pair<int, int>> merged_list;
        while (!min_heap.empty()) {
            merged_list.push_back(min_heap.top());
            min_heap.pop();
        }

        int min_range = INT_MAX;
        int start = 0;
        int end = 0;
        unordered_map<int, int> count;

        int l = 0;
        for (int r = 0; r < merged_list.size(); r++) {
            int idx = merged_list[r].second;
            count[idx]++;

            while (count.size() == k) {
                int range = merged_list[r].first - merged_list[l].first;
                if (range < min_range) {
                    min_range = range;
                    start = l; 
                    end = r;
                }

                int l_idx = merged_list[l].second;
                count[l_idx]--;

                if (count[l_idx] == 0) {
                    count.erase(l_idx);
                }

                l++;
            }
        }

        return {merged_list[start].first, merged_list[end].first};
        
    }
};
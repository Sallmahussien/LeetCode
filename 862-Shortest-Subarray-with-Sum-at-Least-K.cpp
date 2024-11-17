class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int res = INT_MAX;
        long long sum = 0;

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> min_heap;

        for (int r = 0; r < nums.size(); r++) {
            sum += nums[r];

            if (sum >= k) {
                res = min(res, r+1);
            }

            while (!min_heap.empty() && sum - min_heap.top().first >= k) {
                pair<long long, int> prefix_idx = min_heap.top();
                min_heap.pop();

                res = min(res, r-prefix_idx.second);
            }

            min_heap.push({sum, r});
        }

        return res == INT_MAX ? -1 : res;
    }
};
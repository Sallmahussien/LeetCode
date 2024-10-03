class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long total_sum = 0;
        for (int num : nums) {
            total_sum += num;
        }

        int target = total_sum % p;
        if (target == 0) return 0;

        unordered_map<int, int> prefix_map;
        prefix_map[0] = -1;
        int prefix_sum = 0;
        int min_len = INT_MAX;

        for (int i = 0; i < nums.size(); i++) {
            prefix_sum = (prefix_sum + nums[i]) % p;
            int required = (prefix_sum - target + p) % p;

            if (prefix_map.count(required)) {
                min_len = min(min_len, i - prefix_map[required]);
            }
            prefix_map[prefix_sum] = i;
        }

        return min_len == INT_MAX || min_len == nums.size() ? -1 : min_len;
    }
};
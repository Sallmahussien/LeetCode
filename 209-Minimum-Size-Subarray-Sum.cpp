class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0, r = 0;
        int res = INT_MAX;
        int sum = nums[0];

        while (r < nums.size() || l < nums.size()) {
            if (sum < target) {
                if (++r == nums.size()) break;
                sum += nums[r];
            } else {
                res = min(res, r-l+1);
                sum -= nums[l++];
            }
        }

        return res == INT_MAX ? 0 : res;
    }
};
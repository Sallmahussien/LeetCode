class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int b = *max_element(nums.begin(), nums.end());

        int l = 0, r = 0, res = 0;
        for (; r < nums.size(); r++) {
            if (nums[r] == b) {
                res = max(res, r - l + 1);
            } else {
                l = r + 1;
            }
        }

        return res;
    }
};

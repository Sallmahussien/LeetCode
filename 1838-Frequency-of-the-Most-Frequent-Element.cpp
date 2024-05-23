class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int res = 0;
        long long total = 0;
        int window_size = 0;
        int left = 0;

        sort(nums.begin(), nums.end());

        for (int right = 0; right < nums.size(); right++) {
            total += nums[right];
            window_size = right - left + 1;
            if ((long long)nums[right] * (right - left + 1) > total + k) {
                total -= nums[left];
                left++;
            }

            res = max(res, right - left + 1);
        }

        return res;
    }
};
class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        long long res = 0;

        for (int l = 0; l < n - 1; ++l) {
            int low_bound = lower - nums[l];
            int high_bound = upper - nums[l];

            auto h_min = lower_bound(nums.begin() + l + 1, nums.end(), low_bound);
            
            auto h_max = upper_bound(nums.begin() + l + 1, nums.end(), high_bound);

            res += h_max - h_min;
        }

        return res;
    }
};
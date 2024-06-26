class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int min_diff = INT_MAX;
        for (int i = 0; i < nums.size()-k+1; i++) {
            min_diff = min(min_diff, nums[i+k-1] - nums[i]);
        }

        return min_diff;
    }
};
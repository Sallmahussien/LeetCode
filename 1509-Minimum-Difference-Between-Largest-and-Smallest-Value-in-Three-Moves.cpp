class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();
        if (n <= 3) {
            return 0;
        }
        
        sort(nums.begin(), nums.end());

        int min_diff_1 = nums[n-4] - nums[0];
        int min_diff_2 = nums[n-3] - nums[1];
        int min_diff_3 = nums[n-2] - nums[2];
        int min_diff_4 = nums[n-1] - nums[3];
        
        return min({min_diff_1, min_diff_2, min_diff_3, min_diff_4});
    }
};
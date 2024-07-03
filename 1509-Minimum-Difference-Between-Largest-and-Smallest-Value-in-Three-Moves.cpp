class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();
        if (n <= 4) {
            return 0;
        }
        
        sort(nums.begin(), nums.end());
        
        // Consider the following scenarios
        // 1. Change the three smallest values
        int min_diff_1 = nums[n-4] - nums[0];
        // 2. Change the two smallest and the largest value
        int min_diff_2 = nums[n-3] - nums[1];
        // 3. Change the smallest and the two largest values
        int min_diff_3 = nums[n-2] - nums[2];
        // 4. Change the three largest values
        int min_diff_4 = nums[n-1] - nums[3];
        
        // Return the minimum difference
        return min({min_diff_1, min_diff_2, min_diff_3, min_diff_4});
    }
};
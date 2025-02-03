class Solution {
    public int longestMonotonicSubarray(int[] nums) {
        int ans = 1;
        int i = 0;
        int n = nums.length;

        while (i < n-1) {
            boolean isIncreasing = nums[i] < nums[i+1];
            boolean isDecreasing = nums[i] > nums[i+1];

            if (!isIncreasing && !isDecreasing) {
                i++;
                continue;
            }

            int j = i;
            
            while (isIncreasing && j < n-1 && nums[j] < nums[j+1]) {
                j++;
            }

            while (isDecreasing && j < n-1 && nums[j] > nums[j+1]) {
                j++;
            }

            ans = Math.max(ans, j-i+1);
            i = j;
        }

        return ans;
    }
}
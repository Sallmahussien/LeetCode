class Solution {
    public long maximumTripletValue(int[] nums) {
        long res = 0;
        long prefixMax = nums[0];
        long maxDiff = 0;

        for (int k = 1; k < nums.length; k++) {
            res = Math.max(res, maxDiff * nums[k]);

            prefixMax = Math.max(prefixMax, nums[k]);
            maxDiff = Math.max(maxDiff, prefixMax - nums[k]);
        }

        return res;
    }
}
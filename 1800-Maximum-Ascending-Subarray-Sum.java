class Solution {
    public int maxAscendingSum(int[] nums) {
        int sum = nums[0];
        int finalSum = 0;

        for (int i = 1; i < nums.length; i++) {
            if (nums[i] > nums[i-1]) {
                sum += nums[i];
            } else {
                finalSum = Math.max(finalSum, sum);
                sum = nums[i];
            }
        }

        return Math.max(finalSum, sum);
    }
}
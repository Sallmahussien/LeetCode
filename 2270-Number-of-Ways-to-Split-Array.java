class Solution {
    public int waysToSplitArray(int[] nums) {
        long leftSum = 0;
        long rightSum = 0;
        int waysToSplit = 0;

        for (int num : nums) {
            rightSum += num;
        }

        for (int i = 0; i < nums.length - 1; i++) {
            leftSum += nums[i];
            rightSum -= nums[i];

            if (leftSum >= rightSum) {
                waysToSplit++;
            }
        }

        return waysToSplit;
        
    }
}
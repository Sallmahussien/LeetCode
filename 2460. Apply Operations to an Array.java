class Solution {
    public int[] applyOperations(int[] nums) {
        int n = nums.length;
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] == nums[i + 1]) {
                nums[i] *= 2;
                nums[i + 1] = 0;
            }
        }

        int firstZeroIdx = 0;
        while (firstZeroIdx < n && nums[firstZeroIdx] != 0) {
            firstZeroIdx++;
        }

        int firstNonZeroIdx = firstZeroIdx;
        while (firstNonZeroIdx < n && nums[firstNonZeroIdx] == 0) {
            firstNonZeroIdx++;
        }

        while (firstNonZeroIdx < n) {
            nums[firstZeroIdx] = nums[firstNonZeroIdx];
            nums[firstNonZeroIdx] = 0;

            while (firstZeroIdx < n && nums[firstZeroIdx] != 0) {
                firstZeroIdx++;
            }

            while (firstNonZeroIdx < n && nums[firstNonZeroIdx] == 0) {
                firstNonZeroIdx++;
            }
        }

        return nums;        
    }
}

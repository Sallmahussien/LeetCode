class Solution {
    private int binarySearch(int l, int[] nums, int target) {
        int r = nums.length - 1;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (nums[mid] >= target) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return l;
    }
    public long countFairPairs(int[] nums, int lower, int upper) {
        Arrays.sort(nums);
        long res = 0;

        for (int i = 0; i < nums.length; i++) {
            res += (
                binarySearch(i + 1, nums, upper - nums[i] + 1) -
                binarySearch(i + 1, nums, lower - nums[i])
            );
        }

        return res;
    }
}
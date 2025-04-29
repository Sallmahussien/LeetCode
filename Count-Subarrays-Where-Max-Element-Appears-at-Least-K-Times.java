class Solution {
    public long countSubarrays(int[] nums, int k) {
        int max = 0;
        for (int num : nums) {
            max = Math.max(max, num);
        }

        int l = 0;
        long res = 0;
        int count = 0;
        int n = nums.length;
        for (int r = 0; r < n; r++) {
            if (nums[r] == max) {
                count++;
            }

            while (count >= k) {
                res += (n - r);
                if (nums[l] == max) {
                    count--;
                }
                l++;
            }
        }

        return res;
    }
}
class Solution {
    public long countSubarrays(int[] nums, long k) {
        int l = 0;
        long sum = 0;
        long res = 0;

        for (int r = 0; r < nums.length; r++) {
            sum += nums[r];

            while (sum * (r - l + 1) >= k) {
                sum -= nums[l++];
            }

            res += (r - l + 1);
        }

        return res;
    }
}
class Solution {
    public int countSubarrays(int[] nums) {
        int res = 0;

        for (int i = 0; i <= nums.length - 3; i++) {
            if (nums[i] + nums[i+2] == 0.5 * nums[i+1]) res++;
        }

        return res;
    }
}
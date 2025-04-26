class Solution {
    public long countSubarrays(int[] nums, int minK, int maxK) {
        int lastMin = -1;
        int lastMax = -1;
        int bad = -1;
        long res = 0;

        for (int r = 0; r < nums.length; r++) {
            if (nums[r] < minK || nums[r] > maxK) {
                bad = r;
            }

            if (nums[r] == minK) lastMin = r;
            if (nums[r] == maxK) lastMax = r;

            res += Math.max(0, Math.min(lastMin, lastMax) - bad);
        }

        return res;
    }
}
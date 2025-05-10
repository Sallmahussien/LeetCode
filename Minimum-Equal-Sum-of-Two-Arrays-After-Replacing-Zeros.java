class Solution {
    public long minSum(int[] nums1, int[] nums2) {
        long minSum1 = 0, minSum2 = 0;
        boolean canBeIncreased1 = false, canBeIncreased2 = false;

        for (int n: nums1) {
            if (n == 0) {
                canBeIncreased1 = true;
                minSum1++;
            } else {
                minSum1 += n;
            }
        }

        for (int n: nums2) {
            if (n == 0) {
                canBeIncreased2 = true;
                minSum2++;
            } else {
                minSum2 += n;
            }
        }

        if (minSum1 == minSum2 || (minSum1 > minSum2 && canBeIncreased2) || (minSum2 > minSum1 && canBeIncreased1)) {
            return Math.max(minSum1, minSum2);
        }
        return -1;
        
    }
}
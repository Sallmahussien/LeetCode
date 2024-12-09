class Solution {
    public boolean[] isArraySpecial(int[] nums, int[][] queries) {
        int n = nums.length - 1;
        int[] prefixMismatch = new int[n];
        int mismatch = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] % 2 != nums[i+1] % 2) {
                mismatch++;
            }

            prefixMismatch[i] = mismatch;
        }

        boolean[] res = new boolean[queries.length];

        for (int i = 0; i < queries.length; i++) {
            int start = queries[i][0];
            int end = queries[i][1];
            int pairCount = end - start;

            int mismatchCount = (end - 1 >= 0 ? prefixMismatch[end - 1] : 0)
            - (start - 1 >= 0 ? prefixMismatch[start - 1] : 0);

            res[i] = (pairCount == mismatchCount);
        }

        return res;
    }
}
class Solution {
    public int maxAbsoluteSum(int[] nums) {
        int prefix = 0;
        int min = 0;
        int max = 0;
        int res = 0;

        for (int num : nums) {
            prefix += num;

            res = Math.max(res, Math.max(Math.abs(prefix - min), Math.abs(prefix - max)));

            min = Math.min(min, prefix);
            max = Math.max(max, prefix);
        }

        return res;
    }
}
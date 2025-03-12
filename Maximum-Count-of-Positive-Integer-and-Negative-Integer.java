class Solution {
    public int maximumCount(int[] nums) {
        int posCount = 0;
        int negCount = 0;

        for (int n : nums) {
            if (n > 0) posCount++;
            if (n < 0) negCount++;
        }

        return Math.max(posCount, negCount);
    }
}
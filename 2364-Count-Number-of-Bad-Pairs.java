class Solution {
    public long countBadPairs(int[] nums) {
        int n = nums.length;
        Map<Integer, Integer> freqArr = new HashMap<>();
        long totalPairs = (long) n * (n - 1) / 2;
        long goodCount = 0;

        for (int i = 0; i < n; i++) {
            int v = i - nums[i];

            if (freqArr.containsKey(v)) {
                goodCount += freqArr.get(v);
            }

            freqArr.put(v, freqArr.getOrDefault(v, 0) + 1);
        }

        return totalPairs - goodCount;
    }
}
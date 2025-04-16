class Solution {
    public long countGood(int[] nums, int k) {
        long ans = 0;
        long goodPairs = 0;
        Map<Integer, Integer> freqArr = new HashMap<>();
        int l = 0;
        int n = nums.length;

        for (int r = 0; r < n; r++) {
            int count = freqArr.getOrDefault(nums[r], 0);
            goodPairs += count;
            freqArr.put(nums[r], count + 1);

            while (goodPairs >= k) {
                ans += (n - r);
                int freq = freqArr.get(nums[l]);
                goodPairs -= (freq - 1);
                freqArr.put(nums[l], freq - 1);
                l++;
            }
        }

        return ans;
    }
}
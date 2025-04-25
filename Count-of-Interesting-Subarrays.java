class Solution {
    public long countInterestingSubarrays(List<Integer> nums, int modulo, int k) {
        Map<Integer, Integer> freqArr = new HashMap<>();
        long res = 0;
        int prefix = 0;
        freqArr.put(0, 1);

        for (int num : nums) {
            if (num % modulo == k) prefix++;
            res += freqArr.getOrDefault((prefix - k + modulo) % modulo, 0);

            freqArr.put(prefix % modulo, freqArr.getOrDefault(prefix % modulo, 0) + 1);
        }

        return res;
    }
}
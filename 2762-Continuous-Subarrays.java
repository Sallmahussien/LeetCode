class Solution {
    public long continuousSubarrays(int[] nums) {
        TreeMap<Integer, Integer> freqArr = new TreeMap<>();
        int l = 0;
        long count = 0;

        for (int r = 0; r < nums.length; r++) {

            freqArr.put(nums[r], freqArr.getOrDefault(nums[r], 0) + 1);

            while(freqArr.lastEntry().getKey() - freqArr.firstEntry().getKey() > 2) {
                freqArr.put(nums[l], freqArr.get(nums[l]) - 1);

                if (freqArr.get(nums[l]) == 0) {
                    freqArr.remove(nums[l]);
                }

                l++;
            }

            count += r - l + 1;
        }

        return count;
    }
}
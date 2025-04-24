class Solution {
    public int countCompleteSubarrays(int[] nums) {
        Set<Integer> numsSet = new HashSet<>();
        for (int num : nums) {
            numsSet.add(num);
        }

        int distinctsNum = numsSet.size();
        int n = nums.length;
        int l = 0;
        Map<Integer, Integer> freqArr = new HashMap<>();
        int res = 0;

        for (int r = 0; r < nums.length; r++) {
            freqArr.put(nums[r], freqArr.getOrDefault(nums[r], 0) + 1);

            while (freqArr.size() == distinctsNum) {
                res += (n - r);
                freqArr.put(nums[l], freqArr.get(nums[l]) - 1);

                if (freqArr.get(nums[l]) == 0) {
                    freqArr.remove(nums[l]);
                }

                l++;
            }
        }

        return res;
        
    }
}
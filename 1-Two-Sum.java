class Solution {
    public int[] twoSum(int[] nums, int target) {
        Map<Integer, Integer> freqArr = new HashMap<>();
        for (int i = 0; i < nums.length; i++) {
            if (freqArr.containsKey(target - nums[i])) {
                return new int[] {freqArr.get(target - nums[i]), i};
            }
            freqArr.put(nums[i], i);
        }

        return new int[]{};      
    }
}
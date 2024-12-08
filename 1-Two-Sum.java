class Solution {
    public int[] twoSum(int[] nums, int target) {
        Map<Integer, Integer> numsMap = new HashMap<>();


        for (int i = 0; i < nums.length; i++) {
            int secondNum = target - nums[i];
            if (numsMap.containsKey(secondNum)) {
                return new int[] {i, numsMap.get(secondNum)};
            }

            numsMap.put(nums[i], i);
        }

        return new int[] {};
    }
}
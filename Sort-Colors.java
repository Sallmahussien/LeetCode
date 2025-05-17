class Solution {
    public void sortColors(int[] nums) {
        Map<Integer, Integer> freqArr = new HashMap<>();
        for (int num : nums) {
            freqArr.put(num, freqArr.getOrDefault(num, 0) + 1);
        }

        int idx = 0;

        for (int i = 0; i < 3; i++) {
            int count = freqArr.getOrDefault(i, 0);

            for (int j = 0; j < count; j++) {
                nums[idx++] = i;
            }            
        }
    }
}
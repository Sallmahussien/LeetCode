class Solution {
    public int tupleSameProduct(int[] nums) {
        Map<Integer, Integer> freqArr = new HashMap<>();
        int ans = 0;

        for (int i = 0; i < nums.length; i++) {
            for (int j = i + 1; j < nums.length; j++) {
                int mult = nums[i] * nums[j];

                freqArr.put(mult, freqArr.getOrDefault(mult, 0) + 1);
            }
        }

        for (int k : freqArr.values()) {
            if (k >= 2) {
                ans += ((k * (k - 1)) / 2) * 8;
            }
        }

        return ans;
    }
}
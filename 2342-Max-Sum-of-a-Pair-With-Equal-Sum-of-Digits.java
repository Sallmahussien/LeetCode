class Solution {
    public int maximumSum(int[] nums) {
        int ans = -1;
        Map<Integer, Integer> sumToNum = new HashMap<>();

        for (int num : nums) {
            int sum = getSumDigigt(num);

            if (sumToNum.containsKey(sum)) {
                ans = Math.max(ans, num + sumToNum.get(sum));
            }

            sumToNum.put(sum, Math.max(sumToNum.getOrDefault(sum, 0), num));
        }

        return ans;
    }

    private int getSumDigigt(int num) {
        int sum = 0;

        while(num != 0) {
            sum += num % 10;
            num /= 10;
        }

        return sum;
    }
}
class Solution {
    public int countLargestGroup(int n) {
        Map<Integer, Integer> freqArr = new HashMap<>();
        int maxLen = 0;
        for (int i = 1; i <= n; i++) {
            int sum = sumDigits(i);
            int len = freqArr.getOrDefault(sum, 0) + 1;
            freqArr.put(sum, len);
            maxLen = Math.max(maxLen, len);
        }

        int count = 0;
        for (Map.Entry<Integer, Integer> entry : freqArr.entrySet()) {
            if (entry.getValue() == maxLen) count++;
        }


        return count;
    }

    private int sumDigits (int num) {
        int sum = 0;

        while (num > 0) {
            sum += (num % 10);
            num /= 10;
        }

        return sum;
    }
}
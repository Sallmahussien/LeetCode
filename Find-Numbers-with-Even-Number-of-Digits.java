class Solution {
    public int findNumbers(int[] nums) {
        int res = 0;

        for (int num : nums) {
            if (isEven(getDigitsNum(num))) res++;
        }

        return res;
    }

    private int getDigitsNum(int num) {
        int digits = 0;

        while (num > 0) {
            digits++;
            num /= 10;
        }

        return digits;
    }

    private boolean isEven(int n) {
        return n % 2 == 0;
    }
}
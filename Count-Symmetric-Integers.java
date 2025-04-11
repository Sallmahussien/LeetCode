class Solution {
    public int countSymmetricIntegers(int low, int high) {
        int ans = 0;

        for (int i = low; i <= high; i++) {
            String num = String.valueOf(i);
            int n = num.length();

            if (n % 2 == 1) continue;
            int firstHalf = getDigitSum(0, n / 2, num);
            int secondHalf = getDigitSum(n / 2, n, num);

            if (firstHalf == secondHalf) ans++;
        }

        return ans;
    }

    private int getDigitSum(int start, int end, String str) {
        int sum = 0;

        for (int i = start; i < end; i++) {
            sum += str.charAt(i) - '0';;
        }

        return sum;
    }
}
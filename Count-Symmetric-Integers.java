class Solution {
    public int countSymmetricIntegers(int low, int high) {
        int ans = 0;

        for (int i = low; i <= high; i++) {
            if (i >= 10 && i <= 99 && i % 11 == 0) ans++;

            if (i >= 1000 && i <= 9999) {
                int rightHalf = i % 10 + (i / 10) % 10;
                int leftHalf = (i / 100) % 10 + (i / 1000) % 10;

                if (leftHalf == rightHalf) ans++;
            }
        }

        return ans;
    }
}
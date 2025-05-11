class Solution {
    public boolean threeConsecutiveOdds(int[] arr) {
        int n = arr.length;
        for (int i = 0; i < n - 2; i++) {
            if (isOdd(arr[i]) && isOdd(arr[i+1]) && isOdd(arr[i+2])) {
                return true;
            }
        }

        return false;
    }

    private boolean isOdd(int num) {
        return (num & 1) == 1;
    }
}
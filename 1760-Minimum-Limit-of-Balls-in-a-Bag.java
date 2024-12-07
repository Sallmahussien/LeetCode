class Solution {
    private boolean canDivide(int maxBalls, int nums[], int maxOperations) {
        int ops = 0;

        for (int n : nums) {
            ops += (n + maxBalls - 1) / maxBalls - 1;

            if (ops > maxOperations) {
                return false;
            }
        }

        return true;
    }

    public int minimumSize(int[] nums, int maxOperations) {
        int low = 1;
        int high = Arrays.stream(nums).max().getAsInt();

        while (low < high) {
            int mid = (high - low) / 2 + low;

            if (canDivide(mid, nums, maxOperations)) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }
}
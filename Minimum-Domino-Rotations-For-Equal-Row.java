class Solution {
    public int minDominoRotations(int[] tops, int[] bottoms) {
        int ans = Integer.MAX_VALUE;
        int n = tops.length;

        for (int val = 1; val < 7; val++) {
            boolean canApplySwap = true;
            int topSwaps = 0;
            int bottomSwaps = 0;

            for (int i = 0; i < n; i++) {
                if (tops[i] != val && bottoms[i] != val) {
                    canApplySwap = false;
                    break;
                }

                if (tops[i] != val) topSwaps++;
                if (bottoms[i] != val) bottomSwaps++;
            }

            if (canApplySwap) {
                ans = Math.min(ans, Math.min(topSwaps, bottomSwaps));
            }
        }

        return ans == Integer.MAX_VALUE ? -1 : ans;       
    }
}
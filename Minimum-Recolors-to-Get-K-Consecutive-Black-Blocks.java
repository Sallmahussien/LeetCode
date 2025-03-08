class Solution {
    public int minimumRecolors(String blocks, int k) {
        int l = 0;
        int whiteCount = 0;
        int res = Integer.MAX_VALUE;

        for (int r = 0; r < blocks.length(); r++) {
            if (blocks.charAt(r) == 'W') whiteCount++;

            if (r - l + 1 == k) {
                res = Math.min(res, whiteCount);
                if (blocks.charAt(l++) == 'W') whiteCount--;
            }
        }

        return res;
    }
}
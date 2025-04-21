class Solution {
    public long gridGame(int[][] grid) {
        int col = grid[0].length;
        long[] prefixArr = new long[col];
        long prefix = 0;
        long[] suffixArr = new long[col];
        long suffix = 0;

        for (int i = 0; i < col; i++) {
            prefix += grid[0][i];
            suffix += grid[1][col-i-1];

            prefixArr[i] = prefix;
            suffixArr[col-i-1] = suffix;
        }

        long secondRobotScore = Long.MAX_VALUE;

        for (int i = 0; i < col; i++) {
            long score = Math.max(prefixArr[col - 1] - prefixArr[i], suffixArr[0] - suffixArr[i]);
            secondRobotScore = Math.min(secondRobotScore, score);
        }

        return secondRobotScore;
    }
}
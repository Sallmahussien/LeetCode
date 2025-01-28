class Solution {
    private int[][] grid;
    private int[] dy = {1, -1, 0, 0};
    private int[] dx = {0, 0, 1, -1};
    private int numRows;
    private int numCols;

    public int findMaxFish(int[][] grid) {
        this.grid = grid;

        numRows = grid.length;
        numCols = grid[0].length;

        int res = 0;

        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j < numCols; j++) {
                // if (grid[i][j] > 0) { 
                    res = Math.max(res, dfs(i, j));
                // }
            }
        }

        return res;
    }

    private int dfs(int r, int c) {
        if (!isValid(r, c) || grid[r][c] == 0) {
            return 0;
        }

        int res = grid[r][c];
        grid[r][c] = 0;

        for (int i = 0; i < 4; i++) {
            int nextR = r + dx[i];
            int nextC = c + dy[i];
            res += dfs(nextR, nextC);
        }

        return res;
    }

    private boolean isValid(int r, int c) {
        return r >= 0 && r < numRows && c >= 0 && c < numCols; 
    }
}
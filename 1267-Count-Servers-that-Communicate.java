class Solution {
    public int countServers(int[][] grid) {
        int numRows = grid.length;
        int numCols = grid[0].length;
        int[] rows = new int[numRows];
        int[] cols = new int[numCols];

        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j < numCols; j++) {
                if (grid[i][j] == 1) {
                    rows[i] += 1;
                    cols[j] += 1;
                }
            }
        }

        int count = 0;

        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j < numCols; j++) {
                if (grid[i][j] == 1) {
                    if (rows[i] >= 2 || cols[j] >= 2) {
                        count++;
                    }
                }
            }
        }

        return count;
    }
}
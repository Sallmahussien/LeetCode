class Solution {
    public int minCost(int[][] grid) {
        int[][] dirs = { { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } };
        int rows = grid.length, cols = grid[0].length;

        Deque<int[]> deque = new ArrayDeque<>();
        deque.offerFirst(new int[] { 0, 0 });

        int[][] minCost = new int[rows][cols];
        for (int[] row : minCost) {
            Arrays.fill(row, Integer.MAX_VALUE);
        }
        minCost[0][0] = 0;

        while (!deque.isEmpty()) {
            int[] curr = deque.pollFirst();
            int row = curr[0], col = curr[1];

            for (int dir = 0; dir < 4; dir++) {
                int newRow = row + dirs[dir][0];
                int newCol = col + dirs[dir][1];
                int cost = (grid[row][col] != (dir + 1)) ? 1 : 0;

                if (
                    isValid(newRow, newCol, rows, cols) &&
                    minCost[row][col] + cost < minCost[newRow][newCol]
                ) {
                    minCost[newRow][newCol] = minCost[row][col] + cost;

                    if (cost == 1) {
                        deque.offerLast(new int[] { newRow, newCol });
                    } else {
                        deque.offerFirst(new int[] { newRow, newCol });
                    }
                }
            }
        }

        return minCost[rows - 1][cols - 1];
    }

    private boolean isValid(int row, int col, int numRows, int numCols) {
        return row >= 0 && row < numRows && col >= 0 && col < numCols;
    }
}
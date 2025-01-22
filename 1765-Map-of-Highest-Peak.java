class Solution {
    public int[][] highestPeak(int[][] isWater) {
        int numRows = isWater.length;
        int numCols = isWater[0].length;

        int[] dx = {0, 0, 1, -1};
        int[] dy = {1, -1, 0, 0};

        int[][] height = new int[numRows][numCols];

        Queue<int[]> q = new LinkedList<>();

        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j < numCols; j++) {
                if (isWater[i][j] == 1) {
                    q.offer(new int[]{i, j});
                } else {
                    height[i][j] = -1;
                }
            }
        }

        while(!q.isEmpty()) {
            int[] currCell = q.poll();
            int currRow = currCell[0];
            int currCol = currCell[1];

            for (int i = 0; i < 4; i++) {
                int nextRow = currRow + dx[i];
                int nextCol = currCol + dy[i];

                if (
                    isValid(numRows, numCols, nextRow, nextCol)
                    && height[nextRow][nextCol] == -1
                ) {
                    height[nextRow][nextCol] = height[currRow][currCol] + 1;
                    q.offer(new int[]{nextRow, nextCol});
                }
            }
        }

        return height;
    }

    private boolean isValid(int numRows, int numCols, int nextRow, int nextCol) {
        return nextRow >= 0 && nextRow < numRows && nextCol >= 0 && nextCol < numCols;
    }
}
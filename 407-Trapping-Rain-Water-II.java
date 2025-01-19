class Solution {
    private static class Cell implements Comparable<Cell> {
        int row;
        int col;
        int height;

        public Cell(int row, int col, int height) {
            this.row = row;
            this.col = col;
            this.height = height;
        }

        @Override
        public int compareTo(Cell other) {
            return Integer.compare(this.height, other.height);
        }
    }

    public int trapRainWater(int[][] heightMap) {
        int[] dRows = {0, 0, -1, 1};
        int[] dCols = {1, -1, 0, 0};

        int numRows = heightMap.length;
        int numCols = heightMap[0].length;

        boolean[][] visited = new boolean[numRows][numCols];

        PriorityQueue<Cell> boundary = new PriorityQueue<>();

        // add the top and bottom boundary
        for (int i = 0; i < numCols; i++) {
            boundary.offer(new Cell(0, i, heightMap[0][i]));
            boundary.offer(new Cell(numRows - 1, i, heightMap[numRows - 1][i]));

            visited[0][i] = true;
            visited[numRows - 1][i] = true;
        }

        // add the left and right boundary
        for (int i = 0; i < numRows; i++) {
            boundary.offer(new Cell(i, 0, heightMap[i][0]));
            boundary.offer(new Cell(i, numCols - 1, heightMap[i][numCols - 1]));

            visited[i][0] = true;
            visited[i][numCols - 1] = true;
        }

        int res = 0;

        while (!boundary.isEmpty()) {
            Cell currentCell = boundary.poll();
            
            int currentRow = currentCell.row;
            int currentCol = currentCell.col;
            int currentHeight = currentCell.height;

            for (int i = 0; i < 4; i++) {
                int nextRow = currentRow + dRows[i];
                int nextCol = currentCol + dCols[i];

                if (
                    isValidCell(numRows, numCols, nextRow, nextCol)
                    && !visited[nextRow][nextCol]
                ) {
                    int nextHeight = heightMap[nextRow][nextCol];

                    if (nextHeight < currentHeight) {
                        res += (currentHeight - nextHeight);
                    }

                    visited[nextRow][nextCol] = true;

                    boundary.offer(
                        new Cell(nextRow, nextCol, Math.max(nextHeight, currentHeight))
                    );
                }
            }
        }

        return res;
    }

    private boolean isValidCell(int numRows, int numCols, int nextRow, int nextCol) {
        return nextRow >= 0 && nextRow < numRows && nextCol >= 0 && nextCol < numCols;
    }
}
class Solution {
    public int minTimeToReach(int[][] moveTime) {
        int n = moveTime.length;
        int m = moveTime[0].length;

        int[][] directions = {
            {0, 1},
            {0, -1},
            {1, 0},
            {-1, 0}
        };

        int[][] dist = new int[n][m];
        for (int[] row : dist) {
            Arrays.fill(row, Integer.MAX_VALUE);
        }
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> Integer.compare(a[0], b[0]));
        pq.offer(new int[]{0, 0, 0});
        dist[0][0] = 0;

        while (!pq.isEmpty()) {
            int[] curr = pq.poll();
            int t = curr[0], i = curr[1], j = curr[2];

            if (t > dist[i][j]) continue;

            for (int[] direction : directions) {
                int dx = direction[0];
                int dy = direction[1];

                if (isValidDirection(n, m, i, j, dx, dy)) {
                    int nx = i + dx, ny = j + dy;
                    int nextTime = Math.max(t + 1, moveTime[nx][ny] + 1);
                    if (dist[nx][ny] > nextTime) { // relaxation condition
                        dist[nx][ny] = nextTime;
                        pq.offer(new int[]{nextTime, nx, ny});
                    }
                }
            }
        }

        return dist[n-1][m-1];
    }

    private boolean isValidDirection(int n, int m, int x, int y, int dx, int dy) {
        return x + dx >= 0 && x + dx < n && y + dy >= 0 && y + dy < m;
    }
}
class Solution {
    public int minTimeToReach(int[][] moveTime) {
        int n = moveTime.length;
        int m = moveTime[0].length;
        int[][] dist = new int[n][m];
        for (int[] row : dist) {
            Arrays.fill(row, Integer.MAX_VALUE);
        }
        dist[0][0] = 0;

        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> Integer.compare(a[0], b[0]));
        pq.offer(new int[]{0, 0, 0});

        int[][] directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        while (!pq.isEmpty()) {
            int[] curr = pq.poll();
            int t = curr[0], x = curr[1], y = curr[2];

            for (int[] direction : directions) {
                int dx = direction[0];
                int dy = direction[1];

                if (isValidDirection(n, m, x, y, dx, dy)) {
                    int nx = x + dx;
                    int ny = y + dy;
                    int nextTime = Math.max(t, moveTime[nx][ny]) + 1 + (x + y) % 2;

                    if (dist[nx][ny] > nextTime) {
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
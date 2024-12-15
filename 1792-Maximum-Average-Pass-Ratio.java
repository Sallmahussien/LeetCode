class Solution {
    public double maxAverageRatio(int[][] classes, int extraStudents) {
        PriorityQueue<int[]> maxHeap = new PriorityQueue<>((a, b) -> {
            return Double.compare(incrementalGain(b[0], b[1]), incrementalGain(a[0], a[1]));
        });
        
        for (int[] cls : classes) {
            maxHeap.offer(cls);
        }

        while (extraStudents-- > 0) {
            int[] cls = maxHeap.poll();
            cls[0]++;
            cls[1]++;
            maxHeap.offer(cls);
        }

        double totalPassRatio = 0;
        while (!maxHeap.isEmpty()) {
            int[] cls = maxHeap.poll();
            totalPassRatio += (double) cls[0] / cls[1];
        }

        return totalPassRatio / classes.length;
    }

    private double incrementalGain(int pass, int total) {
        return ((double) (pass + 1) / (total + 1)) - ((double) pass / total);
    }
}
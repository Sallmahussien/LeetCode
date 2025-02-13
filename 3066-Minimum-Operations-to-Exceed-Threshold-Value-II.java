class Solution {
    public int minOperations(int[] nums, int k) {
        PriorityQueue<Long> minHeap = new PriorityQueue<>();
        int count = 0;

        for (int n : nums) {
            minHeap.offer((long) n);
        }
        
        while (minHeap.peek() < k && minHeap.size() > 1) {
            long x = minHeap.poll();
            long y = minHeap.poll();

            long newNum = 2 * x + y;
            minHeap.offer(newNum);
            count++;
        }

        return count;
    }
}
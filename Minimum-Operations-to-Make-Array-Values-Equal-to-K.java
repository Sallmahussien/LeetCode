class Solution {
    public int minOperations(int[] nums, int k) {
        PriorityQueue<Integer> maxHeap = new PriorityQueue<>(Collections.reverseOrder());

        for (int num : nums) {
            if (num < k) return -1;
            maxHeap.offer(num);
        }

        int ans = 0;

        while (!maxHeap.isEmpty() && maxHeap.peek() != k) {
            int maxVal = maxHeap.poll();

            while (!maxHeap.isEmpty() && maxHeap.peek() == maxVal) {
                maxHeap.poll();
            }

            ans++;
        }

        return ans;
    }
}
class Solution {
    public int findKthLargest(int[] nums, int k) {
        PriorityQueue<Integer> maxHeap = new PriorityQueue<>(Collections.reverseOrder());
        for (int num : nums) {
            maxHeap.offer(num);
        }

        for (int i = 1; i < k; i++) {
            maxHeap.poll();
        }
        
        return maxHeap.peek();
    }
}
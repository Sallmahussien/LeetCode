class Solution {
    public int[] getFinalState(int[] nums, int k, int multiplier) {
        PriorityQueue<Integer> minHeap = new PriorityQueue<>((a, b) -> {
            if (nums[a] == nums[b]) {
                return Integer.compare(a, b);
            }

            return Integer.compare(nums[a], nums[b]);
        });

        for (int i = 0; i < nums.length; i++) {
            minHeap.offer(i);
        }

        while (k-- > 0) {
            int idx = minHeap.poll();
            nums[idx] *= multiplier;
            minHeap.offer(idx);
        }

        return nums;
    }
}
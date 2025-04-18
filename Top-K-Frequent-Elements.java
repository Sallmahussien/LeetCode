class Solution {
    public int[] topKFrequent(int[] nums, int k) {
        Map<Integer, Integer> freqArr = new HashMap<>();
        for (int n : nums) {
            freqArr.put(n, freqArr.getOrDefault(n, 0) + 1);
        }

        PriorityQueue<Map.Entry<Integer, Integer>> maxHeap = new PriorityQueue<>(
            (a, b) -> Integer.compare(b.getValue(), a.getValue())
        );

        maxHeap.addAll(freqArr.entrySet());

        int[] ans = new int[k];
        for (int i = 0; i < k; i++) {
            ans[i] = maxHeap.poll().getKey();
        }

        return ans;
    }
}
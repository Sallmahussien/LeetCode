class Pair {
    int value;
    int index;

    Pair(int value, int index) {
        this.value = value;
        this.index = index;
    }
}

class Solution {
    public long findScore(int[] nums) {
        int n = nums.length;
        PriorityQueue<Pair> minHeap = new PriorityQueue<>((a, b) -> {
            if (a.value == b.value) {
                return Integer.compare(a.index, b.index);
            }
            return Integer.compare(a.value, b.value);
        });

        for (int i = 0; i < n; i++) {
            minHeap.offer(new Pair(nums[i], i));
        }

        boolean[] marked = new boolean[n];

        long score = 0;

        while (!minHeap.isEmpty()) {
            Pair top = minHeap.poll();
            int value = top.value;
            int idx = top.index;

            if (marked[idx]) continue;

            score += value;
            markIndex(marked, idx);
            markIndex(marked, idx-1);
            markIndex(marked, idx+1);
        }

        return score; 
    }

    private void markIndex(boolean[] marked, int index) {
        if (index >= 0 && index < marked.length) {
            marked[index] = true;
        }
    }
}
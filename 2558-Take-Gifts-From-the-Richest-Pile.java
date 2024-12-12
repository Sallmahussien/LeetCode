class Solution {
    public long pickGifts(int[] gifts, int k) {
        PriorityQueue<Integer> maxHeap = new PriorityQueue<>(Collections.reverseOrder());

        for (int gift : gifts) {
            maxHeap.offer(gift);
        }

        while (k-- > 0) {
            int topGift = maxHeap.poll();
            maxHeap.offer((int) Math.sqrt(topGift));
        }

        long res = 0; 
        while (!maxHeap.isEmpty()) {
            res += maxHeap.poll();
        }

        return res;
        
    }
}
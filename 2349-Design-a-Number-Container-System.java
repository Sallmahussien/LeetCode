class NumberContainers {
    private Map<Integer, PriorityQueue<Integer>> numberToIdxs = null;
    private Map<Integer, Integer> idxToNumber = null;

    public NumberContainers() {
        numberToIdxs = new HashMap<>();
        idxToNumber = new HashMap<>();
    }
    
    public void change(int index, int number) {
        if (idxToNumber.containsKey(index)) {
            int oldNumber = idxToNumber.get(index);
            if (oldNumber == number) return;
        }

        numberToIdxs.computeIfAbsent(number, k -> new PriorityQueue<>()).add(index);

        idxToNumber.put(index, number);        
    }
    
    public int find(int number) {
        if (!numberToIdxs.containsKey(number)) return -1;

        PriorityQueue<Integer> minHeap = numberToIdxs.get(number);

        while (!minHeap.isEmpty() && idxToNumber.get(minHeap.peek()) != number) {
            minHeap.poll();
        }

        return minHeap.isEmpty() ? -1 : minHeap.peek();
    }
}

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers obj = new NumberContainers();
 * obj.change(index,number);
 * int param_2 = obj.find(number);
 */
class Solution {
    public int numRabbits(int[] answers) {
        Map<Integer, Integer> countMap = new HashMap<>();
        
        for (int answer : answers) {
            countMap.put(answer, countMap.getOrDefault(answer, 0) + 1);
        }
        
        int totalRabbits = 0;
        
        for (Map.Entry<Integer, Integer> entry : countMap.entrySet()) {
            int k = entry.getKey();
            int count = entry.getValue();
            
            int groupSize = k + 1;
            int numGroups = (count + groupSize - 1) / groupSize;
            totalRabbits += numGroups * groupSize;
        }
        
        return totalRabbits;
    }
}
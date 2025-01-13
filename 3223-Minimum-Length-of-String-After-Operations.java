class Solution {
    public int minimumLength(String s) {
        Map<Character, Integer> freqArr = new HashMap<>();
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            freqArr.put(c, freqArr.getOrDefault(c, 0) + 1);
        }

        int count = 0;
        for (Integer val : freqArr.values()) {
            while (val >= 3) {
                val -= 2;
            }

            count += val;
        }

        return count;
    }
}
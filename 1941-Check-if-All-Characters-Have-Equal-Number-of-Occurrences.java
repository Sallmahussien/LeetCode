class Solution {
    public boolean areOccurrencesEqual(String s) {
        Map<Character, Integer> freqArr = new HashMap<>();

        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            freqArr.put(c, freqArr.getOrDefault(c, 0) + 1);
        }

        int charCount = freqArr.get(s.charAt(0));

        for (char c : freqArr.keySet()) {
            if (freqArr.get(c) != charCount) {
                return false;
            }
        }

        return true;
    }
}
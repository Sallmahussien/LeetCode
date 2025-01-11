class Solution {
    public boolean canConstruct(String s, int k) {
        int n = s.length();
        if (n < k) {
            return false;
        }

        Map<Character, Integer> freqArr = new HashMap<>();
        for (int i = 0; i < n; i++) {
            char c = s.charAt(i);

            freqArr.put(c, freqArr.getOrDefault(c, 0) + 1);
        }

        int oddsCount = 0;
        for (Map.Entry<Character, Integer> entry : freqArr.entrySet()) {
            if (entry.getValue() % 2 != 0) {
                oddsCount++;
            }
        }

        return oddsCount <= k;
    }
}
class Solution {
    public int countCharacters(String[] words, String chars) {
        Map<Character, Integer> freqArr =  new HashMap<>();
        for (int i = 0; i < chars.length(); i++) {
            char c = chars.charAt(i);
            freqArr.put(c, freqArr.getOrDefault(c, 0) + 1);
        }

        int count = 0;
        for (String word : words) {
            boolean isGood = true;
            Map<Character, Integer> charFreq = new HashMap<>();

            for (int i = 0; i < word.length(); i++) {
                char c = word.charAt(i);
                charFreq.put(c, charFreq.getOrDefault(c, 0) + 1);

                if (freqArr.getOrDefault(c, 0) < charFreq.get(c)) {
                    isGood = false;
                    break;
                }
            }

            if (isGood) {
                count += word.length();
            }
        }


        return count;
        
    }
}
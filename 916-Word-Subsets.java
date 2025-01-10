class Solution {
    public List<String> wordSubsets(String[] words1, String[] words2) {
        Map<Character, Integer> words2Map = new HashMap<>();
        for (String word : words2) {
            Map<Character, Integer> tempMap = new HashMap<>();
            for (char c : word.toCharArray()) {
                tempMap.put(c, tempMap.getOrDefault(c, 0) + 1);
            }

            for (Map.Entry<Character, Integer> entry : tempMap.entrySet()) {
                char key = entry.getKey();
                int count = entry.getValue();
                words2Map.put(key, Math.max(words2Map.getOrDefault(key, 0), count));
            }
        }

        List<String> res = new ArrayList<>();

        for (String word : words1) {

            Map<Character, Integer> words1Map = new HashMap<>();
            for (int i = 0; i < word.length(); i++) {
                char c = word.charAt(i);
                words1Map.put(c, words1Map.getOrDefault(c, 0) + 1);
            }

            boolean isUniversal = true;

            for (Map.Entry<Character, Integer> entry : words2Map.entrySet()) {
                Character key = entry.getKey();
                Integer value = entry.getValue();
                
                if (words1Map.getOrDefault(key, 0) < value) {
                    isUniversal = false;
                    break;
                }
            }

            if (isUniversal) {
                res.add(word);
            }
        }

        return res;
    }
}
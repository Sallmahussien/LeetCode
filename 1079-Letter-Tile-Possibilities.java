class Solution {
    public int numTilePossibilities(String tiles) {
        int[] count = new int[26];
        for (char c : tiles.toCharArray()) {
            count[c - 'A']++;
        }

        Set<String> result = new HashSet<>();
        generatePermutations(count, new StringBuilder(), result);
        
        return result.size();
    }

    private void generatePermutations(int[] count, StringBuilder current, Set<String> result) {
        if (current.length() > 0) {
            result.add(current.toString());
        }

        for (int i = 0; i < 26; i++) {
            if (count[i] > 0) {
                count[i]--;
                current.append((char)(i + 'A'));
                generatePermutations(count, current, result);
                current.deleteCharAt(current.length() - 1);
                count[i]++;
            }
        }
    }
}

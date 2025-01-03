class Solution {
    public int[] vowelStrings(String[] words, int[][] queries) {
        int n = words.length;
        int[] prefixArr = new int[n];
        int prefix = 0;
        Set<Character> vowels = Set.of('a', 'e', 'i', 'o', 'u');

        for (int i = 0; i < n; i++) {
            String word = words[i];
            char start = word.charAt(0);
            char end = word.charAt(word.length()-1);

            if (vowels.contains(start) && vowels.contains(end)) {
                prefix++;
            }

            prefixArr[i] = prefix;
        }

        int q = queries.length;
        int[] res = new int[q];
        for (int i = 0; i < q; i++) {
            int[] query = queries[i];

            res[i] = prefixArr[query[1]] - (query[0] > 0 ? prefixArr[query[0]-1] : 0);
        }

        return res;
        
    }
}
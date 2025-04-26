class Solution {
    public String mergeAlternately(String word1, String word2) {
        int n1 = word1.length();
        int n2 = word2.length();

        int idx = 0;
        StringBuilder str = new StringBuilder();

        while (idx < n1 || idx < n2) {
            if (idx < n1) str.append(word1.charAt(idx));
            if (idx < n2) str.append(word2.charAt(idx));
            idx++;
        }

        return str.toString();
        
    }
}
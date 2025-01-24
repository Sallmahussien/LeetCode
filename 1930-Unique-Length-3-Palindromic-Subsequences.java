class Solution {
    public int countPalindromicSubsequence(String s) {
        int n = s.length();
        Set<String> seen = new HashSet<>();

        int[] left = new int[26];
        int[] right = new int[26];

        for (char c : s.toCharArray()) {
            right[c - 'a']++;
        }

        for (int i = 0; i < n; i++) {
            char middle = s.charAt(i);
            right[middle - 'a']--;

            for (char c = 'a'; c <= 'z'; c++) {
                if (left[c - 'a'] > 0 && right[c - 'a'] > 0) {
                    seen.add("" + c + middle + c);
                }
            }

            left[middle - 'a']++;
        }

        return seen.size();
    }
}
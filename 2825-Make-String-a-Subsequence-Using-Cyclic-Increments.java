class Solution {
    public boolean canMakeSubsequence(String str1, String str2) {
        int i = 0, j = 0;

        while (i < str1.length() && j < str2.length()) {
            char nextChar = (char) ((str1.charAt(i) - 'a' + 1) % 26 + 'a');
            if (str1.charAt(i) == str2.charAt(j) || nextChar == str2.charAt(j)) { 
                j++;
            }

            i++;
        }

        return j == str2.length();
    }
}
class Solution {
    public int countPrefixSuffixPairs(String[] words) {
        int count = 0;

        for (int i = 0; i < words.length; i++) {
            for (int j = i + 1; j < words.length; j++) {
                if (isPrefixAndSuffix(words[i], words[j])) {
                    count++;
                }
            }
        }

        return count;
    }

    private boolean isPrefixAndSuffix(String str1, String str2) {
        int n1 = str1.length();
        int n2 = str2.length();

        if (n2 < n1) {
            return false;
        }

        String prefix = str2.substring(0, n1);
        String suffix = str2.substring(n2-n1);

        return str1.equals(prefix) && str1.equals(suffix);
    }
}
class Solution {
    public String longestCommonPrefix(String[] strs) {
        String prefix = strs[0];

        for (int i = 0; i < strs.length; i++) {
            String str = strs[i];

            while (!str.startsWith(prefix)) {
                prefix = prefix.substring(0, prefix.length() - 1);

                if (prefix.isEmpty()) return \\;
            }

        }

        return prefix;
    }
}
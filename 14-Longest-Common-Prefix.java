class Solution {
    public String longestCommonPrefix(String[] strs) {
        if (strs == null || strs.length == 0) return \\;

        StringBuilder prefix = new StringBuilder(strs[0]);

        for (int i = 1; i < strs.length; i++) {
            int idx = 0;
            while (idx < prefix.length() && idx < strs[i].length() && strs[i].charAt(idx) == prefix.charAt(idx)) {
                idx++;
            }
            prefix.setLength(idx);

            if (prefix.length() == 0) return \\;
        }

        return prefix.toString();
    }
}
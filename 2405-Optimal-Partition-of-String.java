class Solution {
    public int partitionString(String s) {
        boolean[] seen = new boolean[26];
        int res = 0;
        
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);

            if (seen[c - 'a']) {
                res++;
                seen = new boolean[26];
            }

            seen[c - 'a'] = true;
        }
        
        return ++res;
    }
}
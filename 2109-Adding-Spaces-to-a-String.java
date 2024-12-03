class Solution {
    public String addSpaces(String s, int[] spaces) {
        StringBuilder res = new StringBuilder();
        int idx = 0;

        for (int i = 0; i < s.length(); i++) {
            while (idx < spaces.length && spaces[idx] == i) {
                res.append(" ");
                idx++;
            }
            res.append(s.charAt(i));
        }

        return res.toString();
    }
}
class Solution {
    public String shiftingLetters(String s, int[] shifts) {
        int n = shifts.length;
        char[] res = new char[n];
        long count = 0;

        for (int i = n-1; i >= 0; i--) {
            count = (count + shifts[i]) % 26;
            int next = 97 + ((s.charAt(i) - 97 + (int) count) % 26);
            res[i] = (char) next;
        }

        return new String(res);
    }
}
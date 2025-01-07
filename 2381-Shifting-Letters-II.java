class Solution {
    public String shiftingLetters(String s, int[][] shifts) {
        int n = s.length();

        int[] diff = new int[n + 1];

        for (int[] shift : shifts) {
            int start = shift[0];
            int end = shift[1];
            int direction = shift[2];

            if (direction == 1) {
                // forward
                diff[start] += 1;
                diff[end + 1] -= 1;
            } else {
                // backward
                diff[start] -= 1;
                diff[end + 1] += 1;
            }
        }

        int shiftsCount = 0;
        char[] res = new char[n];

        for (int i = 0; i < n; i++) {
            shiftsCount += diff[i];
            shiftsCount %= 26;
            int next = 97 + ((s.charAt(i) - 97 + shiftsCount + 26) % 26);
            res[i] = (char) next;
        }

        return new String(res);
    }
}
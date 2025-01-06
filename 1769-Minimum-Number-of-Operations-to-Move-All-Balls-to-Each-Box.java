class Solution {
    public int[] minOperations(String boxes) {
        int n = boxes.length();
        int[] ans = new int[n];

        int balls = 0;
        int moves = 0;

        // left to right
        for (int i = 0; i < n; i++) {
            moves += balls;
            
            ans[i] = moves;

            balls += (boxes.charAt(i) - 48);
        }

        balls = 0;
        moves = 0;

        // right to left
        for (int i = n - 1; i >= 0; i--) {
            moves += balls;
            
            ans[i] += moves;

            balls += (boxes.charAt(i) - 48);

        }

        return ans;
    }
}
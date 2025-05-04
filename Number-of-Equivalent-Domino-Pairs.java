class Solution {
    public int numEquivDominoPairs(int[][] dominoes) {
        int res = 0;
        int n = dominoes.length;

        for (int i = 0; i < n; i++) {
            int a = dominoes[i][0];
            int b = dominoes[i][1];

            for (int j = i+1; j < n; j++) {
                int c = dominoes[j][0];
                int d = dominoes[j][1];

                if ((a == c && b == d) || (a == d && b == c)) {
                    res++;
                }
            }
        }

        return res;
    }
}
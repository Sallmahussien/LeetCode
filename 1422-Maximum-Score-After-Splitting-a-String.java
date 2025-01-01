class Solution {
    public int maxScore(String s) {
        int res = 0;
        int onesInRight = 0;
        int zerosInLeft = 0;

        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (c == '1') {
                onesInRight++;
            }
        }

        for (int i = 0; i < s.length()-1; i++) {
            char c = s.charAt(i);
            if (c == '1') {
                onesInRight--;
            } else {
               zerosInLeft++; 
            }

            int score = onesInRight + zerosInLeft;
            res = Math.max(res, score);
        }

        return res;
    }
}
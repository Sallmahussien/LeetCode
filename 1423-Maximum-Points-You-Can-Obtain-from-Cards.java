class Solution {
    public int maxScore(int[] cardPoints, int k) {
        int n = cardPoints.length;
        int windowSize = n - k;

        int totalSum = 0;
        int windowSum = 0;

        for (int i = 0; i < n; i++) {
            if (i < windowSize) {
                windowSum += cardPoints[i];
            }

            totalSum += cardPoints[i];
        }

        int score = totalSum - windowSum;

        for (int i = windowSize; i < n; i++) {
            windowSum -= cardPoints[i - windowSize];
            windowSum += cardPoints[i];

            score = Math.max(score, totalSum - windowSum);
        }

        return score;
    }
}
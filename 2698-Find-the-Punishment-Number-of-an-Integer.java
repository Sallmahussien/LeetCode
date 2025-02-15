class Solution {
    public int punishmentNumber(int n) {
        int ans = 0;

        for (int i = 1; i <= n; i++) {
            if (isPunishment(i, i * i)) {
                ans += (i * i);
            }
        }

        return ans;
    }

    private boolean isPunishment(int target, int square) {
        String squareStr = String.valueOf(square);
        return canPartition(squareStr, 0, target, 0);
    }

    private boolean canPartition(String s, int index, int target, int currentSum) {
        if (index == s.length()) {
            return currentSum == target;
        }

        int num = 0;
        for (int i = index; i < s.length(); i++) {
            num = num * 10 + (s.charAt(i) - '0');
            
            if (canPartition(s, i + 1, target, currentSum + num)) {
                return true;
            }
        }

        return false;
    }
}
class Solution {
    public int minCost(String colors, int[] neededTime) {
        int curr = 1;
        int prev = 0;
        int cost = 0;

        for (; curr < colors.length(); curr++) {
            boolean haveSameColor = false;

            if (colors.charAt(curr) == colors.charAt(prev)) {
                cost += Math.min(neededTime[curr], neededTime[prev]);
                haveSameColor = true;
            }

            if (!haveSameColor || (haveSameColor && neededTime[prev] < neededTime[curr]) ) {
                prev = curr;
            }
        }

        return cost;
    }
} 
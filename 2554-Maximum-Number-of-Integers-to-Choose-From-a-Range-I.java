class Solution {
    public int maxCount(int[] banned, int n, int maxSum) {
        Set<Integer> bannedSet = new HashSet<>();
        for (int i : banned) {
            bannedSet.add(i);
        }

        int sum = 0;
        int count = 0;

        for (int i = 1; i <= n; i++) {
            if (!bannedSet.contains(i)) {
                sum += i;

                if (sum > maxSum) break;

                count++;
            }
        }
        return count;
    }
}
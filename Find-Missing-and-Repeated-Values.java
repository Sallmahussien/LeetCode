class Solution {
    public int[] findMissingAndRepeatedValues(int[][] grid) {
        int n = grid.length;
        Set<Integer> gridSet = new HashSet<>();
        int repeatedNum = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (gridSet.contains(grid[i][j])) {
                    repeatedNum = grid[i][j];
                }

                gridSet.add(grid[i][j]);
            }
        }

        int missingNum = 0;
        for (int i = 1; i <= Math.pow(n, 2); i++) {
            System.out.println(i);
            if (!gridSet.contains(i)) {
                missingNum = i;
                break;
            }
        }

        return new int[]{repeatedNum, missingNum};
    }
}
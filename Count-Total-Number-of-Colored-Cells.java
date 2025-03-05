class Solution {
    public long coloredCells(int n) {
        long outerCells = 0;
        long totalCells = 1;

        for (int i = 0; i < n; i++) {
            totalCells += outerCells;
            outerCells += 4;
        }
        return totalCells; 
    }
}
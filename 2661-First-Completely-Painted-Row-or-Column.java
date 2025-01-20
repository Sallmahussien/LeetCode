class Solution {
    public int firstCompleteIndex(int[] arr, int[][] mat) {
        Map<Integer, int[]> numWithPos = new HashMap<>();

        int numRows = mat.length;
        int numCols = mat[0].length;

        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j < numCols; j++) {
                numWithPos.put(mat[i][j], new int[]{i, j});
            }
        }

        int[] rows = new int[numRows];
        int[] cols = new int[numCols];

        int res = -1;

        for (int i = 0; i < arr.length; i++) {
            int n = arr[i];
            int rowIdx = numWithPos.get(n)[0];
            int colIdx = numWithPos.get(n)[1];

            rows[rowIdx]++;
            if (rows[rowIdx] ==  numCols) {
                res = i;
                break;
            }

            cols[colIdx]++;
            if (cols[colIdx] == numRows) {
                res = i;
                break;
            }
        }

        return res;
    }
}
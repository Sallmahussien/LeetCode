class Solution {
    public int[] findThePrefixCommonArray(int[] A, int[] B) {
        int n = A.length;
        int[] counterArr = new int[n+1];

        int[] prefixCommonArray = new int[n];
        int count = 0;

        for (int i = 0; i < n; i++) {
            // counterArr[A[i]]++;
            if (++counterArr[A[i]] == 2) count++;

            // counterArr[B[i]]++;
            if (++counterArr[B[i]] == 2) count++;

            prefixCommonArray[i] = count;
        }

        return prefixCommonArray;
    }
}
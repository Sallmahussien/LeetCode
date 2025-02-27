class Solution {
    public int lenLongestFibSubseq(int[] arr) {
        Set<Integer> arrMap = new HashSet<>();

        for (int i = 0; i < arr.length; i++) {
            arrMap.add(arr[i]);
        }

        int lastNum, prevLastNum;
        int res = 0;

        for (int i = 0; i < arr.length; i++) {
            for (int j = i + 1; j < arr.length; j++) {
                prevLastNum = arr[i];
                lastNum = arr[j];
                int len = 2;
                int obtainedValue = lastNum + prevLastNum;

                while (arrMap.contains(obtainedValue)) {
                    len++;
                    prevLastNum = lastNum;
                    lastNum = obtainedValue;
                    obtainedValue = prevLastNum + lastNum;

                    res = Math.max(res, len);
                }
            }

        }

        return res;
    }
}

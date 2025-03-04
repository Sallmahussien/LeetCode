class Solution {
    public int[] pivotArray(int[] nums, int pivot) {
        List<Integer> lessThan = new ArrayList<>();
        List<Integer> greaterThan = new ArrayList<>();
        int pivotCount = 0;

        for (int n : nums) {
            if (n == pivot) pivotCount++;
            else if (n < pivot) lessThan.add(n);
            else greaterThan.add(n);
        }

        int n = nums.length;
        int[] res = new int[n];
        int idx = 0;

        for (int i = 0; i < lessThan.size() && idx < n; i++) {
            res[idx++] = lessThan.get(i);
        }

        while (idx < n && pivotCount-- != 0) {
            res[idx++] = pivot;
        }

        for (int i = 0; i < greaterThan.size() && idx < n; i++) {
            res[idx++] = greaterThan.get(i);
        }

        return res;
    }
}
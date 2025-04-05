class Solution {
    public int subsetXORSum(int[] nums) {
        List<Integer> current = new ArrayList<>();
        List<List<Integer>> subsets = new ArrayList<>();

        getAllSubsets(0, nums, current, subsets);
        
        int res = 0;
        for (List<Integer> subset : subsets) {
            int xor = 0;
            for (int num : subset) {
                xor ^= num;
            }

            res += xor;
        }

        return res;
    }

    private void getAllSubsets(
        int idx, int[] nums, List<Integer> current, List<List<Integer>> subsets
    ) {
        if (idx == nums.length) {
            subsets.add(new ArrayList<>(current));
            return;
        }

        current.add(nums[idx]);
        getAllSubsets(idx + 1, nums, current, subsets);

        current.remove(current.size() - 1);
        getAllSubsets(idx + 1, nums, current, subsets);
    }
}
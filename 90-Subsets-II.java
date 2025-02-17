class Solution {
    public List<List<Integer>> subsetsWithDup(int[] nums) {
        Set<List<Integer>> uniqueSubsets = new HashSet<>();
        List<Integer> curr = new ArrayList<>();
        Arrays.sort(nums);

        backtrack(0, curr, uniqueSubsets, nums);

        return uniqueSubsets.stream().collect(Collectors.toList());
    }

    private void backtrack(
        int idx, List<Integer> curr, Set<List<Integer>> uniqueSubsets, int[]nums
    ) {
        if (idx == nums.length) {
           uniqueSubsets.add(new ArrayList<>(curr));
           return; 
        }

        curr.add(nums[idx]);
        backtrack(idx + 1, curr, uniqueSubsets, nums);

        curr.remove(curr.size() - 1);
        backtrack(idx + 1, curr, uniqueSubsets, nums);
    }
}
class Solution {
    public int subsetXORSum(int[] nums) {
        return dfs(0, 0, nums);
    }

    private int dfs(int idx, int currentXor, int[] nums) {
        if (idx == nums.length) {
            return currentXor;
        }
        
        return dfs(idx + 1, currentXor ^ nums[idx], nums) + dfs(idx + 1, currentXor, nums);
    }
}
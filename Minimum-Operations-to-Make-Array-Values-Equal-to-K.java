class Solution {
    public int minOperations(int[] nums, int k) {
        Set<Integer> set = new HashSet<>();
        int ans = 0;

        for (int num : nums) {
            if (num < k) return -1;
            
            if (set.contains(num) || num == k) continue;

            set.add(num);
            ans++;
        }

        return ans;
    }
}
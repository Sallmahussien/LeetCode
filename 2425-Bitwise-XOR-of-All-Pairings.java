class Solution {
    public int xorAllNums(int[] nums1, int[] nums2) {
        // Set<Integer> nums1Set = new HashSet<>();
        // Set<Integer> nums2Set = new HashSet<>();

        // for (int n : nums1) {
        //     nums1Set.add(n);
        // }

        // for (int n : nums2) {
        //     nums2Set.add(n);
        // }

        int size1 = nums1.length;
        int size2 = nums2.length;

        // both even
        if (size1 % 2 == 0 && size2 % 2 == 0) return 0;

        // both odd
        if (size1 % 2 == 1 && size2 % 2 == 1) {
            int res = 0;

            for (int n : nums1) {
                res ^= n;
            }

            for (int n : nums2) {
                res ^= n;
            }

            return res;
        }

        int res = 0;
        if (size1 % 2 == 0) {
            for (int n : nums1) {
                res ^= n;
            }

        } else {
            for (int n : nums2) {
                res ^= n;
            }
        }

        return res;
    }
}
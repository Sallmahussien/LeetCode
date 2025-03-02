class Solution {
    public int[][] mergeArrays(int[][] nums1, int[][] nums2) {
        int n = nums1.length, m = nums2.length;
        int i = 0, j = 0;
        List<int[]> res = new ArrayList<>();

        while (i < n && j < m) {
            if (nums1[i][0] == nums2[j][0]) {
                res.add(new int[]{nums1[i][0], nums1[i][1] + nums2[j][1]});
                i++;
                j++;
            } else if (nums1[i][0] < nums2[j][0]) {
                res.add(nums1[i]);
                i++;
            } else {
                res.add(nums2[j]);
                j++;
            }
        }

        while (i < n) {
            res.add(nums1[i]);
            i++;
        }

        while (j < m) {
            res.add(nums2[j]);
            j++;
        }

        return res.toArray(new int[res.size()][]);        
    }
}

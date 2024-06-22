class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
    //     int res = 0;

    //     for (int i = 0; i < nums.size(); i++) {
    //         int count = 0;
    //         for (int j = i; j < nums.size(); j++) {
    //             if (nums[j] % 2 != 0) count++;

    //             if (count == k) res += 1;
    //         }
    //     }

    //    return res;

        int l = 0, m = 0, res = 0, odds = 0;
        for (int r = 0; r < nums.size(); r++) {
            if (nums[r] % 2 != 0) odds++;

            if (odds > k) {
                l = m + 1;
                m++;
                odds--;
            }

            if (odds == k) {
                while(nums[m] % 2 == 0) m++;
                res += m - l + 1;
            }
        }

        return res;
    }
};
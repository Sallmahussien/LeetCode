class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        // if (nums.size() < 3) return 0;
        // int res = 0;
        // int l;

        // for (l = 0; l < nums.size()-2; l++) {
        //     int n = nums[l] - nums[l+1];
        //     int r;
        //     for (r = l; r < nums.size()-1; r++) {
        //         if (nums[r] - nums[r+1] != n) break;
        //     }

        //     if (r-l+1 >= 3) res += r - l - 1;
        // }

        // return res;

        if (nums.size() < 3) return 0;
        int res = 0;
        int curr_len = 0;

        for (int i = 2; i < nums.size(); i++) {
            if (nums[i] - nums[i-1] == nums[i-1] - nums[i-2]) {
                curr_len++;
                res += curr_len;
            } else {
                curr_len = 0;
            }
        }

        return res;
    }
};
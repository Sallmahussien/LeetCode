class Solution {
public:
    int maximumSwap(int num) {
        if (num == 0) return 0;

        int n = num;
        vector<int> nums;
        while (n) {
            nums.push_back(n % 10);
            n /= 10;
        }

        if (nums.size() == 1) return num;

        reverse(nums.begin(), nums.end());

        for (int l = 0; l < nums.size()-1; l++) {
            int max = nums[l+1];
            int max_idx = l+1;

            for (int r = l+1; r < nums.size(); r++) {
                if (nums[r] >= max) {
                    max = nums[r];
                    max_idx = r;
                }
            }

            if (max > nums[l]) {
                // swap
                swap(nums[l], nums[max_idx]);
                break;
            }
        }

        int res = 0;
        for (int nn : nums) {
            res = (res * 10) + nn;
        }

        return res;
    }
};
class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        const int MOD = 1e9 + 7;
        sort(nums.begin(), nums.end());

        int n = nums.size();

        vector<int> pow2(n, 1);
        for (int i = 1; i < n; ++i) {
            pow2[i] = (pow2[i - 1] * 2) % MOD;
        }

        int r = nums.size()-1;
        long long res = 0;
        for (int l = 0; l < nums.size(); l++) {
            while (l <= r && nums[l] + nums[r] > target) r--;

            if (l <= r) {
                res += pow2[r - l];
                res %= MOD;
            }
        }

        return res;
    }
};
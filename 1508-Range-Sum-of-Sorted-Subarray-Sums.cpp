class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> sub;

        for (int start = 0; start < n; start++) {
            int sum = 0;
            for (int end = start; end < n; end++) {
                sum += nums[end];
                sub.push_back(sum);
            }
        }

        sort(sub.begin(), sub.end());

        int res = 0;
        int mod = 1000000007;
        for (int i = left - 1; i < right; i++) {
            res += sub[i];
            res %= mod;
        }

        return res;
    }
};
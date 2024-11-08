class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n = nums.size();
        vector<int> res(n);
        int prefix_xor = 0;
        int max_xor = pow(2, maximumBit) - 1;

        for (int i = 0; i < n; i++) {
            prefix_xor ^= nums[i];
            res[n-1-i] = prefix_xor ^ max_xor;
        }

        return res;
    }
};
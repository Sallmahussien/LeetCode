class Solution {
private:
    void bitsUpdate(vector<int>& bits, int n, int delta) {
        for (int i = 0; i < 32; i++) {
            if (n & (1 << i)) {
                bits[i] += delta;
            }
        }
    }

    int getCurrOr(vector<int>& bits) {
        int curr_or = 0;
        for (int i = 0; i < 32; i++) {
            if (bits[i]) curr_or += (1 << i);
        }

        return curr_or;
    }

public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int res = INT_MAX;
        int l = 0;
        int or_val = 0;
        vector<int> bits(32);

        for (int r = 0; r < nums.size(); r++) {
            bitsUpdate(bits, nums[r], 1);

            int curr_or = getCurrOr(bits);

            while (l <= r && curr_or >= k) {
                res = min(res, r-l+1);

                bitsUpdate(bits, nums[l], -1);
                curr_or = getCurrOr(bits);
                l++;
            }
        }

        return res == INT_MAX ? -1 : res;
    }
};
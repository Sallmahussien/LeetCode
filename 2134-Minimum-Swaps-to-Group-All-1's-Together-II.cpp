class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int res = INT_MAX;
        int ones_count = 0;

        for (int num : nums) {
            if (num == 1) ones_count++;
        }

        if (ones_count == 0) return 0;
        
        int zeros_count = 0;
        int n = nums.size();

        for (int start = 0, end = 0; start < n; end++) {
            if (nums[end % n] == 0) zeros_count++;

            if (end-start+1 == ones_count) {
                res = min(res, zeros_count);
                if (nums[start++] == 0) zeros_count--;
            }
        }

        return res;
    }
};
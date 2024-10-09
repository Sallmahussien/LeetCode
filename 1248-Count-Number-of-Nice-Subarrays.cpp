class Solution {
private:
    int get_leading_even(vector<int>& nums, int l) {
        int res = 0;

        for (int i = l; nums[i] % 2 == 0; i++) {
            res++;
        }

        return res;
    }

public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int count = 0;
        int l = 0, odd_count = 0;

        for (int r = 0; r < nums.size(); r++) {
            if (nums[r] % 2 != 0) odd_count++;

            while (odd_count > k) {
                if (nums[l] % 2 != 0) odd_count--;
                l++;
            }

            if (odd_count == k) {
                count += 1 + get_leading_even(nums, l);
            }
        }

        return count;
    }
};
class Solution {
private:
    void reverse(vector<int>& nums, int l, int r) {

        while (l <= r) swap(nums[l++], nums[r--]);
    }
public:
    void rotate(vector<int>& nums, int k) {
        // int n = nums.size();
        // k %= n;

        // while (k--) {
        //     int num = nums[n-1];
        //     for (int i = n-1; i > 0; i--) {
        //         nums[i] = nums[i-1];
        //     }

        //     nums[0] = num;
        // }

        k %= nums.size();

        reverse(nums, 0, nums.size()-1);
        reverse(nums, 0, k-1);
        reverse(nums, k, nums.size()-1);
    }
};
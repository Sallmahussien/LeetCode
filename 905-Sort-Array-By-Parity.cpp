class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int l = 0;

        while (l < nums.size() && nums[l] % 2 == 0) l++;

        for (int r = l+1; r < nums.size(); r++) {
            if (nums[r] % 2 == 0) {
                swap(nums[l], nums[r]);
                l++;
            }
        }

        return nums;
    }
};
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // int i = 0, j = 1;

        // while (j < nums.size()) {
        //     if (nums[i] == 0) {
        //         while(j < nums.size() && nums[j] == 0) j++;
        //         if (j == nums.size()) break;
        //         nums[i] = nums[j];
        //         nums[j] = 0;
        //     }
        //     i++;
        //     j++;
        // }

        
        int l = 0, r = 0;
        for (; l < nums.size() && r < nums.size(); l++, r++) {
            if (nums[l] == 0) {
                while (r < nums.size() && nums[r] == 0) r++;
            }

            if (r == nums.size()) break;
            swap(nums[l], nums[r]);
        }
    }
};
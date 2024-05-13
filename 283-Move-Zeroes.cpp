class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0, j = 1;

        while (j < nums.size()) {
            if (nums[i] == 0) {
                while(j < nums.size() && nums[j] == 0) j++;
                if (j == nums.size()) break;
                nums[i] = nums[j];
                nums[j] = 0;
            }
            i++;
            j++;
        }        
    }
};
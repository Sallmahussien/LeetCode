class Solution {
private:
    int getSetBit(int num) {
        int res = 0;

        while (num) {
            if (num % 2 == 1) res += 1;
            num /= 2;
        }

        return res;
    }

public:
    bool canSortArray(vector<int>& nums) {
        unordered_map<int, int> nums_to_set_bits;
        for (int num : nums) {
            nums_to_set_bits[num] = getSetBit(num);
        }

        for (int i = 1; i < nums.size(); i++) {
            for (int j = i; j > 0; j--) {
                if (nums[j] < nums[j-1]) {
                    if (nums_to_set_bits[nums[j]] != nums_to_set_bits[nums[j-1]]) {
                        return false;
                    }

                    swap(nums[j], nums[j-1]);
                    
                }
            }
        }

        return true;
    }
};
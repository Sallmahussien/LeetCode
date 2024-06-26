class Solution {
private:
    bool isIncreasing(vector<int>& nums) {
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < nums[i-1]) return false;
        }

        return true;
    }

    bool isDecreasing(vector<int>& nums) {
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i-1]) return false;
        }

        return true;
    }
public:
    bool isMonotonic(vector<int>& nums) {
        // return isIncreasing(nums) || isDecreasing(nums);

        bool isInc = true, isDec = true;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < nums[i-1]) isInc = false;
            if (nums[i] > nums[i-1]) isDec = false;
        }

        return isInc || isDec;
    }
};
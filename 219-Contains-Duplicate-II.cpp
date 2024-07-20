class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> freq_arr;

        for (int i = 0; i < nums.size(); i++) {
            if (!freq_arr.count(nums[i])) freq_arr[nums[i]] = i;
            else {
                if (i - freq_arr[nums[i]] <= k) return true;
                freq_arr[nums[i]] = i;
            }
        }

        return false;
    }
};
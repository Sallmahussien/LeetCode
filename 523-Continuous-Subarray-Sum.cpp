class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int prefixSum = 0;
        unordered_map<int, int> reminderIdx = {
            {0, -1}
        };

        for (int i = 0; i < nums.size(); i++) {
            prefixSum += nums[i];
            int reminder = prefixSum % k;
            if (!reminderIdx.count(reminder)) reminderIdx[reminder] = i;
            else {
                if (i - reminderIdx[reminder] >= 2) return true;
            }
        }

        return false;
    }
};
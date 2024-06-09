class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int prefixSum = 0;
        int arrNum = 0;
        unordered_map<int, int> freq_arr;
        freq_arr[0] = 1;

        for (int num : nums) {
            prefixSum += num;
            if (freq_arr.count(prefixSum - k)) arrNum += freq_arr[prefixSum - k];

            freq_arr[prefixSum]++;
        }

        return arrNum;
    }
};
class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int res = 0;

        // for (int i = 0; i < nums.size(); i++) {
        //     for (int j = i + 1; j < nums.size(); j++) {
        //         if (nums[i] == nums[j]) res ++;
        //     }
        // }

        unordered_map<int, int> freq_arr;

        for (int num : nums) freq_arr[num]++;

        for (auto pair : freq_arr) res += pair.second * (pair.second - 1) / 2;

        return res;
    }
};
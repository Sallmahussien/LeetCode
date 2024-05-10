class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // first solution
        // int size = nums.size();
        // vector<int> result;
        // for (int i = 0; i < size; i++) {
        //     for (int j = i + 1; j < size; j++) {
        //         if (nums[i] + nums[j] == target) {
        //             result.push_back(i);
        //             result.push_back(j);
        //             return result;
        //         }
        //     }
        // }
        // return result;

        // second solution
        // map<int, int> value_idx;
        // for (int idx = 0; idx < nums.size(); idx++) {
        //     value_idx[nums[idx]] = idx;
        // }

        // for (int idx = 0; idx < nums.size(); idx++) {
        //     int num = target - nums[idx];
        //     int searched_idx = value_idx[num];
        //     if (searched_idx && searched_idx !=idx) return {idx, searched_idx};
        // }
        // return vector<int>();

        // third solution
        map<int, int> value_idx;
        for (int idx = 0; idx < nums.size(); idx++) {
            int current_num = nums[idx];
            int num = target - current_num;

            if (value_idx.find(num) != value_idx.end()) {
                return {value_idx[num], idx};
            }

            value_idx[current_num] = idx;
        }

        return vector<int>();
    }
};
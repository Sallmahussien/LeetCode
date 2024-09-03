class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int res = 0;
        int l = 0;
        unordered_set<int> unique_nums;
        int sum = 0;

        for (int r = 0; r < nums.size(); r++) {
            if (!unique_nums.count(nums[r])) {
                unique_nums.insert(nums[r]);
                sum += nums[r];
            } else {
                // number is found in the set
                res = max(res, sum);
                int idx = l;
                for (; idx < r && nums[idx] != nums[r]; idx++) {
                    unique_nums.erase(nums[idx]);
                    sum -= nums[idx];
                }

                l = idx + 1;
                cout << l << endl;
            }
        }

        res = max(res, sum);

        return res;
        
    }
};
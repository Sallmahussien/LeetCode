class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        // vector<int> res(nums.size());

        // for (int i = 0; i < nums.size(); i++) {
        //     res[i] = (int)pow(nums[i], 2);
        // }

        // sort(res.begin(), res.end());

        // return res;

        vector<int> res(nums.size());

        int left = 0, right = nums.size() - 1;
        int idx = nums.size() - 1;

        while (left <= right) {
            int left_pow = pow(nums[left], 2);
            int right_pow = pow(nums[right], 2);

            if (left_pow > right_pow) {
                res[idx] = left_pow;
                left++;
            } else {
                res[idx] = right_pow;
                right--;
            }
            idx--;
        }

        return res;
    }
};
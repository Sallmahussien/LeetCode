class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        // brute force solution => o(n^3)
        // int res = 0; 

        // for (int i = 0; i < nums.size(); i++) {
        //     for (int j = i; j < nums.size(); j++) {

        //         int minSub = nums[i];
        //         int maxSub = nums[i];

        //         for (int k = i; k <= j; k++) {
        //             minSub = min(minSub, nums[k]);
        //             maxSub = max(maxSub, nums[k]);
        //         }

        //         if (maxSub - minSub <= limit) {
        //             res = max(res, j - i + 1);
        //         }

        //     }
        // }
        // return res;

        int l = 0;
        int res = 0;
        deque<int> max_sub;
        deque<int> min_sub;

        for (int r = 0; r < nums.size(); r++) {
            while (!max_sub.empty() && nums[r] > max_sub.back()) max_sub.pop_back();
            while (!min_sub.empty() && nums[r] < min_sub.back()) min_sub.pop_back();

            max_sub.push_back(nums[r]);
            min_sub.push_back(nums[r]);

            while (max_sub.front() - min_sub.front() > limit) {
                if (nums[l] == max_sub.front()) max_sub.pop_front();
                if (nums[l] == min_sub.front()) min_sub.pop_front();
                l++;
            }

            res = max(res, r - l + 1);
        }

        return res;
    }
};
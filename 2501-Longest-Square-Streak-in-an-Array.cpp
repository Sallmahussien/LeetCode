class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        unordered_set<int> squared_nums (nums.begin(), nums.end());
        int res = -1;

        for (int i = 0; i < nums.size(); i++) {
            long long tail = nums[i];
            int count = 1;

            if (tail > INT_MAX / tail) continue;

            while (squared_nums.count(tail * tail)) {
                count++;
                tail *= tail;

                if (tail > INT_MAX / tail) break;
            }

            if (count >= 2) res = max(res, count);
        }

        return res;
    }
};
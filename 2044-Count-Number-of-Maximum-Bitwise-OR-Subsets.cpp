class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int max_or = 0;
        for (int num : nums) {
            max_or |= num;
        }

        int count = 0;

        function<void(int, int)> dfs = [&](int index, int current_or) {
            if (index == nums.size()) {
                if (current_or == max_or) {
                    count++;
                }
                return;
            }

            dfs(index + 1, current_or | nums[index]);

            dfs(index + 1, current_or);
        };

        dfs(0, 0);

        return count;
    }
};

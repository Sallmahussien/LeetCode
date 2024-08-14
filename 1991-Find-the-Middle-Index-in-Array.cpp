class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n);
        vector<int> postfix(n);

        int prefix_sum = 0;
        int postfix_sum = 0;

        for (int i = 0; i < n; i++) {
            prefix_sum += nums[i];
            prefix[i] = prefix_sum;
        }

        for (int i = n-1; i >= 0; i--) {
            postfix_sum += nums[i];
            postfix[i] = postfix_sum;
        }

        for (int i = 0; i < n; i++) {
            if (prefix[i] == postfix[i]) return i;
        }

        return -1;
    }
};
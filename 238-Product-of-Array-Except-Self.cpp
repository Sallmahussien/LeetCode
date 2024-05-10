class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // int prefix = 1;
        // int n = nums.size();
        // bool has_zero = false;
        // vector<int> res(n);

        // for (int num: nums) {
        //     if (num == 0) {
        //         has_zero = true;
        //         continue;
        //     }

        //     prefix *= num;
        // }

        // for (int i = 0; i < n; i++) {
        //     if (has_zero) {
        //         if (nums[i] != 0) res[i] = 0;
        //         else res[i] = prefix;
        //     } else res[i] = prefix / nums[i];
        // }

        // return res;

        // answer one with extra memory
        // int n = nums.size();
        // vector<int> prefix(n);
        // vector<int> postfix(n);

        // prefix[0] = nums[0];
        // postfix[n-1] = nums[n-1];

        // for (int i = 1; i < n; i++) {
        //     prefix[i] = prefix[i-1] * nums[i];
        // }

        // for (int i = n-2; i >= 0; i--) {
        //     postfix[i] = postfix[i+1] * nums[i];
        // }

        // vector<int> res(n);
        // res[0] = postfix[1];
        // res[n-1] = prefix[n-2];

        // for (int i = 1; i < n - 1; i++) {
        //     res[i] = prefix[i-1] * postfix[i+1]; 
        // }

        // return res;

        // answer two with no extra memory
        int n = nums.size();
        vector<int> ans(n);
        ans[0] = 1;
        int prefix = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            ans[i] = prefix;
            prefix *= nums[i];
        }

        int postfix = nums[n-1];
        for (int i = n-2; i >= 0; i--) {
            ans[i] *= postfix;
            postfix *= nums[i];
        }

        return ans;
    }
};
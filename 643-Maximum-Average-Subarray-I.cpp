class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double res = INT_MIN;
        int sum = 0;

        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];

            if (i >= k) sum -= nums[i-k];

            if (i+1 >= k) res = max(res, (double)sum/k);
        }


        return res;
    }
};
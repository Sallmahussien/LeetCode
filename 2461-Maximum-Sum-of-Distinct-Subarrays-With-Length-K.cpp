class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long res = 0;
        long long sum = 0;
        unordered_set<int> distinct_window;
        int start = 0;


        for (int i = 0; i < nums.size(); i++) {
            while (distinct_window.count(nums[i])) {
                distinct_window.erase(nums[start]);
                sum -= nums[start];
                start++;
            }

    
            distinct_window.insert(nums[i]);
            sum += nums[i];


            if (i-start+1 == k) {
                res = max(res, sum);
                distinct_window.erase(nums[start]);
                sum -= nums[start];
                start++;
            }
        }

        return res;
    }
};
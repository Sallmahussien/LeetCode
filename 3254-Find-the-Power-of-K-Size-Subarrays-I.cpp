class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> res;

        for (int i = 0; i <= n-k; i++) {
            bool is_increasing = true;
            for (int j = i+1; j < i+k; j++) {
                if (nums[j]-nums[j-1] != 1) {
                    is_increasing = false;
                    break;
                }
            }


            if (is_increasing) {
                res.push_back(nums[i+k-1]);
            } else {
                res.push_back(-1);
            }
        }
        return res;
    }
};
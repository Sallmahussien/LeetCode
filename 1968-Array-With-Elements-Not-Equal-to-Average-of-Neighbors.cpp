class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> res;
        int l = 0, r = nums.size()-1;

        while (l <= r) {
            if (l == r) res.push_back(nums[l++]);
            else {
                res.push_back(nums[l++]);
                res.push_back(nums[r--]);
            }
        } 

        return res;
    }
};
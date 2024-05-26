class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> freq_arr;

        for (int num: nums) {
            freq_arr[num]++;
        }

        vector<int> res;
        for (int i = 1; i <= n; i++) {
            if (!freq_arr.count(i)) res.push_back(i);
        }

        return res;
    }
};
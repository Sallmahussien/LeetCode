class Solution {
private:
    int atMost(vector<int>& nums, int k) {
        int res = 0;
        int l = 0;

        unordered_map<int, int> freq_arr;
        for (int r = 0; r < nums.size(); r++) {
            freq_arr[nums[r]]++;

            while (freq_arr.size() > k) {

                freq_arr[nums[l]]--;
                if (freq_arr[nums[l]] == 0) freq_arr.erase(nums[l]);
                l++;
            }

            res += r-l+1;
        }
        
        return res;
    }

public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k-1);
    }
};
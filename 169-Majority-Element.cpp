class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> freq_arr;
        int n = nums.size() / 2;
        int res;

        for (int num: nums) {
            freq_arr[num]++;
            if (freq_arr[num] > n) {
                res = num;
                break;
            }
        }

        return res;
    }
};
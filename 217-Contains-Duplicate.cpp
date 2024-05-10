class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int, int> freq_arr;

        for (int num: nums) {
            freq_arr[num]++;

            if (freq_arr[num] > 1) {
                return true;
            }
        }

        return false;        
    }
};
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // using hash map
        // map<int, int> freq_arr;
        // int n = nums.size() / 2;
        // int res;

        // for (int num: nums) {
        //     freq_arr[num]++;
        //     if (freq_arr[num] > n) {
        //         res = num;
        //         break;
        //     }
        // }

        // return res;

        // using boyer moore algo
        int res = 0, count = 0;
        for (int num: nums) {
            if (count == 0) res = num;

            count += (res == num) ? 1 : -1;
        }

        return res;
    }
};
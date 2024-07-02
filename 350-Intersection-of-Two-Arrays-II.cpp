class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> freq_arr;

        for (int num: nums1) freq_arr[num]++;

        vector<int> res;
        for (int num : nums2) {
            if (freq_arr.count(num) && freq_arr[num] > 0) {
                freq_arr[num]--;
                res.push_back(num);
            }
        }

        return res;
    }
};
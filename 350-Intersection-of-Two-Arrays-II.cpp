class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        // map<int, int> freq_arr;

        // for (int num: nums1) freq_arr[num]++;

        // vector<int> res;
        // for (int num : nums2) {
        //     if (freq_arr.count(num) && freq_arr[num] > 0) {
        //         freq_arr[num]--;
        //         res.push_back(num);
        //     }
        // }

        // return res;

        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        vector<int> res;
        for (int i = 0, j = 0; i < nums1.size() && j < nums2.size(); i++) {
            
            while (j < nums2.size() && nums2[j] < nums1[i]) j++;

            if (j == nums2.size()) break;

            if (nums1[i] == nums2[j]) res.push_back(nums2[j++]);
        }

        return res;
    }
};
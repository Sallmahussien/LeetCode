class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        // vector<int> res;
        // unordered_set<int> unique_nums;

        // sort(nums1.begin(), nums1.end());
        // sort(nums2.begin(), nums2.end());

        // int i = 0, j = 0;

        // while (i < nums1.size() && j < nums2.size()) {
        //     if (nums1[i] == nums2[j] && !unique_nums.count(nums1[i])) {
        //         res.push_back(nums1[i]);
        //         unique_nums.insert(nums1[i]);
        //         i++, j++;
        //     } else if (nums1[i] < nums2[j]) i++;
        //     else j++;
        // }

        // return res;

        unordered_map<int, int> freq_arr;
        vector<int> res;

        for (int num : nums1) freq_arr[num]++;

        for (int num : nums2) {
            if (freq_arr.count(num) && freq_arr[num] != 0) {
                res.push_back(num);
                freq_arr[num] = 0;
            }
        }

        return res; 
    }
};
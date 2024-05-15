class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> num_next;
        vector<int> res(nums1.size());
      
        for (int i = 0; i < nums2.size(); i++) {
            for (int j = i+1; j < nums2.size(); j++) {
                if (nums2[j] > nums2[i]) {
                    num_next[nums2[i]] = nums2[j];
                    break;
                }
            }
        }

        for (int i = 0; i < nums1.size(); i++) {
            res[i] = (num_next.count(nums1[i])) ? num_next[nums1[i]] : -1;
        }

        return res;
    }
};
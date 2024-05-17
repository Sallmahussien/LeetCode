class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        // o(n^2)
        // unordered_map<int, int> num_next;
        // vector<int> res(nums1.size());
      
        // for (int i = 0; i < nums2.size(); i++) {
        //     for (int j = i+1; j < nums2.size(); j++) {
        //         if (nums2[j] > nums2[i]) {
        //             num_next[nums2[i]] = nums2[j];
        //             break;
        //         }
        //     }
        // }

        // for (int i = 0; i < nums1.size(); i++) {
        //     res[i] = (num_next.count(nums1[i])) ? num_next[nums1[i]] : -1;
        // }

        // return res;

        // motonic stack
        int n1 = nums1.size();
        vector<int> res(n1, -1);
        unordered_map<int, int> num_idx;

        for (int i = 0; i < n1; i++) {
            num_idx[nums1[i]] = i;
        }

        stack<int> next_greater;

        for (int num: nums2) {
            while (!next_greater.empty() && num > next_greater.top()) {
                int ele = next_greater.top();
                next_greater.pop();

                int idx = num_idx[ele];
                res[idx] = num;
            }
            
            if (num_idx.count(num)) next_greater.push(num);
        }

        return res;
    }
};
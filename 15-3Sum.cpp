class Solution {
private:
    struct VectorHash {
        std::size_t operator()(const std::vector<int>& v) const {
            std::size_t hash = 0;
            for (int num : v) {
                hash ^= std::hash<int>{}(num) + 0x9e3779b9 + (hash << 6) + (hash >> 2);
            }
            return hash;
        }
    };


public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // unordered_set<vector<int>, VectorHash> distinct_triplets;
        // vector<vector<int>> res;

        // for (int l = 0; l < nums.size(); l++) {
        //     for (int mid = l+1; mid < nums.size(); mid++) {
        //         int val = nums[l] + nums[mid];
        //         int num = 0 - val;
        //         for (int r = mid+1; r < nums.size(); r++) {
        //             if (val + nums[r] == 0) {
        //                 vector<int> three_sum = {nums[l], nums[mid], nums[r]};
        //                 sort(three_sum.begin(), three_sum.end());

        //                 if (!distinct_triplets.count(three_sum)) {
        //                     distinct_triplets.insert(three_sum);
        //                     res.push_back(three_sum);
        //                 }
        //             }
        //         }
        //     }
        // }

        // return res;


        vector<vector<int>> res;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++) {
            if (i != 0 && nums[i] == nums[i-1]) continue;

            int l = i+1, r = nums.size()-1;
            while(l < r) {
                int three_sum = nums[i] + nums[l] + nums[r];
                if (three_sum > 0) r--;
                else if (three_sum < 0) l++;
                else {
                    res.push_back({nums[i], nums[l], nums[r]});
                    l++;
                    while (l < r && nums[l] == nums[l-1]) l++;
                }
            }
        }

        return res;
    }
};
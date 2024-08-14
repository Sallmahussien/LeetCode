class Solution {
private:
    int countPairs(vector<int>& nums, int mid) {
        int count = 0;
        int j = 1;

        for (int i = 0; i < nums.size(); i++) {
            for (; j < nums.size() && nums[j] - nums[i] <= mid; j++) {
            }

            count += j - i - 1;
        }
    
        return count;
    }

public:
    int smallestDistancePair(vector<int>& nums, int k) {
        // brute force solution
        // vector<int> pairs;

        // for (int i = 0; i < nums.size(); i++) {
        //     for (int j = i+1; j < nums.size(); j++) {
        //         pairs.push_back(abs(nums[i] - nums[j]));
        //     }
        // }

        // sort(pairs.begin(), pairs.end());

        // cout << pairs.size() << endl;

        // return pairs.size() >= k ? pairs[k-1] : 0;

        sort(nums.begin(), nums.end());
        int n = nums.size() - 1;
        int l = 0, h = nums[n] - nums[0];

        while (l < h) {
            int mid = l + (h - l) / 2;
            int count = countPairs(nums, mid);

            if (count < k) l = mid + 1;
            else h = mid;
        }

        return l;
    }
};
class Solution {
private:
    void print_arr(vector<int>& arr) {
        for (int num: arr) cout << num << " ";

        cout << endl;
    }

public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int min = INT_MAX;

        for (int i = 0; i <= nums.size() - k; i++) {
            int diff = nums[i+k-1] - nums[i];
            if (min > diff) min = diff;
        }

        return min;        
    }
};
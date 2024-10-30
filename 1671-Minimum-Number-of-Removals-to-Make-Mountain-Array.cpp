class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        vector<int> lis(n, 1);

        for (int i = 0; i < n; i++) {
            for (int j = i-1; j >= 0; j--) {
                if (nums[i] > nums[j])
                    lis[i] = max(1+lis[j], lis[i]);
            }
        }

        vector<int> lds(n, 1);
        for (int i = n-1; i >=0; i--) {
            for (int j = i+1; j < n; j++){
                if (nums[i] > nums[j])
                    lds[i] = max(1+lds[j], lds[i]);
            }
        }

        int res = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (lis[i] > 1 && lds[i] > 1)
                res = min(res, n-lis[i]-lds[i]+1);
        }

        return res;
    }
};
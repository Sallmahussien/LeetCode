class NumArray {
private:
    vector<int> prefix_sum;

public:
    NumArray(vector<int>& nums) {
        int prefix = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            prefix_sum.push_back(prefix);
            prefix += nums[i];
        }

        prefix_sum.push_back(prefix);

    }
    
    int sumRange(int left, int right) {
        return left == 0 ? prefix_sum[right] :  prefix_sum[right] - prefix_sum[left - 1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
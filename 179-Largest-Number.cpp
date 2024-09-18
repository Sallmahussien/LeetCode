class Solution {
private:
    string concatNums (int num1, int num2) {
        return to_string(num1) + to_string(num2);
    }

public:
    string largestNumber(vector<int>& nums) {
        for (int i = 1; i < nums.size(); i++) {
            for (int j = i; j > 0; j--) {
                string concat1 = concatNums(nums[j], nums[j-1]);
                string concat2 = concatNums(nums[j-1], nums[j]);
                if (concat1 < concat2) break;
                else {
                    swap(nums[j], nums[j-1]);
                }

            }
        }

        string res = \\;
        for (int num : nums) {
            if (res == \0\ && num == 0) break;
            res += to_string(num);
        }

        return res;
    }
};
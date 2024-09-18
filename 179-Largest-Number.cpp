class Solution {
private:
    static bool compare (int a, int b) {
        string strA = to_string(a);
        string strB = to_string(b);
        return strA + strB > strB + strA;
    }

public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), compare);

        if (nums[0] == 0) return \0\;

        string res = \\;
        for (int num : nums) {
            res += to_string(num);
        }

        return res;
    }
};

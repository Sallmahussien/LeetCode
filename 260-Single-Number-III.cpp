class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xorResult = 0;
        
        for (int num: nums) xorResult ^= num;

        int different_bit = 1;

        while (!(different_bit & xorResult)) different_bit <<= 1;

        int a = 0, b = 0;
        for (int  num: nums) {
            if (num & different_bit) a ^= num;
            else b ^= num;
        }

        return {a, b};
    }
};
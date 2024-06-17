class Solution {
public:
    bool judgeSquareSum(int c) {
        long long a = 0;

        while (a * a <= c) {
            double b = sqrt(c - (a * a));
            if (b == (int)b) return true;

            a += 1;
        }

        return false;
    }
};